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

void Widget::propagateEvent(sf::Event event) {
    (void) event;
}

void Widget::dispatchEvent(sf::Event event) {
    (void) event;
}
