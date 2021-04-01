/*
 * my_hunter
 */

#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Text.hpp"

Text::Text(std::string content, std::string fontPath) {

    this->font.loadFromFile(fontPath);

    this->text.setString(content);
    this->text.setFont(this->font);

    this->text.setCharacterSize(20);
    this->text.setFillColor(sf::Color::Black);

}

Text::~Text() {}

void Text::draw(sf::IntRect bounds, sf::RenderWindow *window) {

    this->text.setPosition(sf::Vector2f(
        bounds.left,
        bounds.top
    ));

    window->draw(this->text);
}

void Text::setContent(std::string content) {
    this->text.setString(content);
}

void Text::setForeground(sf::Color foreground) {
    this->text.setFillColor(foreground);
}

void Text::setSize(int size) {
    this->text.setCharacterSize(size);
}

std::pair<int, int> Text::getSize() {

    std::pair<int, int> size;

    size.first = this->text.getLocalBounds().width;
    size.second = this->text.getCharacterSize();

    return size;
}
