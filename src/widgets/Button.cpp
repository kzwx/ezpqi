/*
 * my_hunter
 */

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Text.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/CenterConstraint.hpp"
#include "../constraints/PixelConstraint.hpp"

#include <iostream>

Button::Button(std::string content, std::string fontPath) {

    this->text = std::make_shared<Text>(content, fontPath);

    this->setBackground(sf::Color::White);
    this->setBorder(sf::Color(209, 209, 209), 1);

    this->text->setForeground(sf::Color(65, 65, 65));

    this->add(this->text, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<PixelConstraint>(this->text->getSize().first),
        std::make_shared<PixelConstraint>(this->text->getSize().second + 3)
    ));

    this->addMouseListener(this);
}

Button::~Button() {}

void Button::onMousePressed(int x, int y) {
    (void) x;
    (void) y;
}

void Button::onMouseReleased(int x, int y) {
    (void) x;
    (void) y;
}

void Button::onMouseMoved(int x, int y) {
    (void) x;
    (void) y;
}

void Button::onMouseEntered(int x, int y) {
    (void) x;
    (void) y;

    this->setBackground(sf::Color(45, 146, 253));
    this->text->setForeground(sf::Color::White);
}

void Button::onMouseExited(int x, int y) {
    (void) x;
    (void) y;

    this->setBackground(sf::Color::White);
    this->text->setForeground(sf::Color(65, 65, 65));
}
