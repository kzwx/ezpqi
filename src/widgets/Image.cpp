/*
 * my_hunter
 */

#include <memory>
#include <SFML/Graphics.hpp>
#include "Image.hpp"
#include "Texture.hpp"
#include "Widget.hpp"

Image::Image(std::shared_ptr<Texture> texture) {

    this->shape.setTexture(texture->texture, false);

    this->texture = texture; // keep the texture in memory

}

Image::~Image() {}

void Image::draw(sf::IntRect bounds, sf::RenderWindow *window) {
    (void) bounds;

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

void Image::resize(sf::IntRect rect) {

    this->shape.setTextureRect(rect);

}
