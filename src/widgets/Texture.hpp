/*
 * my_hunter
 */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Texture {
    public:
        Texture(std::string path, sf::IntRect area);
        virtual ~Texture();

        sf::Texture *texture;
};

#endif
