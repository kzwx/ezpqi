/*
 * my_hunter
 */

#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <SFML/Graphics.hpp>
#include "Widget.hpp"

class Composite : public Widget {
    public:
        Composite();
        virtual ~Composite();

        virtual void draw(sf::IntRect bounds, sf::RenderWindow *window) override;

        void setBackground(sf::Color background);
        void setBorder(sf::Color color, int thickness);

    protected:
        sf::RectangleShape shape;
};

#endif
