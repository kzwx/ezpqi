/*
 * my_hunter
 */

#include <memory>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Widget.hpp"
#include "../constraints/Constraints.hpp"

void Widget::add(std::shared_ptr<Widget> child, std::shared_ptr<Constraints> constraints) {

    this->children.push_back(
        std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>(constraints, child)
    );

}

void Widget::drawAll(sf::IntRect bounds, sf::RenderWindow *window) {

    this->draw(bounds, window);

    this->bounds = bounds;

    std::vector<std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>>::iterator it = this->children.begin();
    std::vector<std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>>::iterator end = this->children.end();

    while (it != end) {

        std::shared_ptr<Constraints> constraints = (*it).first;
        std::shared_ptr<Widget> child = (*it).second;

        child->drawAll(
            constraints->process(bounds),
            window
        );

        it++;
    }
}

void Widget::addMousePressedListener(MousePressedListener listener) {
    this->mousePressedListener = listener;
}

void Widget::addMouseReleasedListener(MouseReleasedListener listener) {
    this->mouseReleasedListener = listener;
}

void Widget::addMouseMovedListener(MouseMovedListener listener) {
    this->mouseMovedListener = listener;
}

void Widget::addMouseEnteredListener(MouseEnteredListener listener) {
    this->mouseEnteredListener = listener;
}

void Widget::addMouseExitedListener(MouseExitedListener listener) {
    this->mouseExitedListener = listener;
}

void Widget::addFocusedInListener(FocusedInListener listener) {
    this->focusedInListener = listener;
}

void Widget::addFocusedOutListener(FocusedOutListener listener) {
    this->focusedOutListener = listener;
}

void Widget::addKeyPressedListener(KeyPressedListener listener) {
    this->keyPressedListener = listener;
}

void Widget::propagateEvent(sf::Event event) {

    std::vector<std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>>::iterator it = this->children.begin();
    std::vector<std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>>::iterator end = this->children.end();

    while (it != end) {

        std::shared_ptr<Widget> child = (*it).second;

        child->dispatchEvent(event);

        it++;
    }
}

static bool isCollide(int x, int y, sf::IntRect bounds) {
    return (
        x >= bounds.left && x <= bounds.left + bounds.width &&
        y >= bounds.top && y <= bounds.top + bounds.height
    );
}

void Widget::dispatchEvent(sf::Event event) {

    /*
     * mousePressed
     * focusedIn
     */
    if (
        event.type == sf::Event::MouseButtonPressed && isCollide(event.mouseButton.x, event.mouseButton.y, this->bounds)
    ) {

        if (this->mousePressedListener)
            this->mousePressedListener(event.mouseButton.x, event.mouseButton.y);

        if (!this->isFocused && this->focusedInListener)
            this->focusedInListener();

        this->isFocused = true;
    }

    /*
     * focusedOut
     */
    if (
        event.type == sf::Event::MouseButtonPressed && !isCollide(event.mouseButton.x, event.mouseButton.y, this->bounds)
    ) {

        if (this->isFocused && this->focusedOutListener)
            this->focusedOutListener();

        this->isFocused = false;
    }

    /*
     * mouseReleased
     */
    if (
        event.type == sf::Event::MouseButtonReleased && isCollide(event.mouseButton.x, event.mouseButton.y, this->bounds)
    ) {

        if (this->mouseReleasedListener)
            this->mouseReleasedListener(event.mouseButton.x, event.mouseButton.y);
    }

    /*
     * mouseMoved
     * mouseEntered
     */
    if (
        event.type == sf::Event::MouseMoved && isCollide(event.mouseMove.x, event.mouseMove.y, this->bounds)
    ) {

        if (this->mouseMovedListener)
            this->mouseMovedListener(event.mouseMove.x, event.mouseMove.y);

        if (this->mouseEnteredListener && !this->isMouseOver)
            this->mouseEnteredListener(event.mouseMove.x, event.mouseMove.y);

        this->isMouseOver = true;
    }

    /*
     * mouseExited
     */
    if (
        event.type == sf::Event::MouseMoved && !isCollide(event.mouseMove.x, event.mouseMove.y, this->bounds)
    ) {

        if (this->mouseExitedListener && this->isMouseOver)
            this->mouseExitedListener(event.mouseMove.x, event.mouseMove.y);

        this->isMouseOver = false;
    }

    /*
     * keyPressed
     */
    if (
        event.type == sf::Event::TextEntered
    ) {

        if (this->keyPressedListener && this->isFocused)
            this->keyPressedListener(event.text.unicode);
    }

    this->propagateEvent(event);
}
