/*
 * my_hunter
 */

#include <string>
#include <SFML/Graphics.hpp>
#include "Texture.hpp"

Texture::Texture(std::string path, sf::IntRect area) {

    this->texture = new sf::Texture();

    this->texture->loadFromFile(path, area);

}

Texture::~Texture() {
    delete this->texture;
}
