/*
 * my_hunter
 */

#include <SFML/Graphics.hpp>
#include "Composite.hpp"
#include "Widget.hpp"

Composite::Composite() {

    this->shape = sf::RectangleShape();

}

Composite::~Composite() {}

void Composite::draw(sf::IntRect bounds, sf::RenderWindow *window) {

    this->shape.setPosition(sf::Vector2f(
        bounds.left,
        bounds.top
    ));

    this->shape.setSize(sf::Vector2f(
        bounds.width,
        bounds.height
    ));

    window->draw(this->shape);
}

void Composite::setBackground(sf::Color background) {
    this->shape.setFillColor(background);
}

void Composite::setBorder(sf::Color color, int thickness) {
    this->shape.setOutlineColor(color);
    this->shape.setOutlineThickness(thickness);
}
