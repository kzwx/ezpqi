/*
 * my_hunter
 */

#include <memory>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Widget.hpp"
#include "../constraints/Constraints.hpp"
#include "../listeners/MouseListener.hpp"

void Widget::add(std::shared_ptr<Widget> child, std::shared_ptr<Constraints> constraints) {

    this->children.push_back(
        std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>(constraints, child)
    );

}

void Widget::clear() {
    this->children.clear();
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

void Widget::addFocusListener(FocusListener *listener) {
    this->focusListener = listener;
}

void Widget::addKeyboardListener(KeyboardListener *listener) {
    this->keyboardListener = listener;
}

void Widget::addMouseListener(MouseListener *listener) {
    this->mouseListener = listener;
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

        if (this->mouseListener)
            this->mouseListener->onMousePressed(event.mouseButton.x, event.mouseButton.y);

        if (!this->isFocused && this->focusListener)
            this->focusListener->onFocusIn();

        this->isFocused = true;
    }

    /*
     * focusedOut
     */
    if (
        event.type == sf::Event::MouseButtonPressed && !isCollide(event.mouseButton.x, event.mouseButton.y, this->bounds)
    ) {

        if (this->isFocused && this->focusListener)
            this->focusListener->onFocusOut();

        this->isFocused = false;
    }

    /*
     * mouseReleased
     */
    if (
        event.type == sf::Event::MouseButtonReleased && isCollide(event.mouseButton.x, event.mouseButton.y, this->bounds)
    ) {

        if (this->mouseListener)
            this->mouseListener->onMouseReleased(event.mouseButton.x, event.mouseButton.y);
    }

    /*
     * mouseMoved
     * mouseEntered
     */
    if (
        event.type == sf::Event::MouseMoved && isCollide(event.mouseMove.x, event.mouseMove.y, this->bounds)
    ) {

        if (this->mouseListener)
            this->mouseListener->onMouseMoved(event.mouseMove.x, event.mouseMove.y);

        if (this->mouseListener && !this->isMouseOver)
            this->mouseListener->onMouseEntered(event.mouseMove.x, event.mouseMove.y);

        this->isMouseOver = true;
    }

    /*
     * mouseExited
     */
    if (
        event.type == sf::Event::MouseMoved && !isCollide(event.mouseMove.x, event.mouseMove.y, this->bounds)
    ) {

        if (this->mouseListener && this->isMouseOver)
            this->mouseListener->onMouseExited(event.mouseMove.x, event.mouseMove.y);

        this->isMouseOver = false;
    }

    /*
     * keyPressed
     */
    if (
        event.type == sf::Event::TextEntered
    ) {

        if (this->keyboardListener && this->isFocused)
            this->keyboardListener->onKeyPressed(event.text.unicode);
    }

    this->propagateEvent(event);
}
