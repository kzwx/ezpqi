/*
 * my_hunter
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "Texture.hpp"
#include "Widget.hpp"

class Image : public Widget {
    public:
        Image(std::shared_ptr<Texture> texture);
        virtual ~Image();

        virtual void draw(sf::IntRect bounds, sf::RenderWindow *window) override;

        void resize(sf::IntRect rect);

    protected:
        sf::RectangleShape shape;

        std::shared_ptr<Texture> texture;
};

#endif
