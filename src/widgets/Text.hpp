/*
 * my_hunter
 */

#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Widget.hpp"

class Text : public Widget {
    public:
        Text(std::string content, std::string fontPath);
        virtual ~Text();

        virtual void draw(sf::IntRect bounds, sf::RenderWindow *window) override;

        void setContent(std::string content);
        void setForeground(sf::Color foreground);
        void setSize(int size);

        std::pair<int, int> getSize();

    protected:
        sf::Text text;
        sf::Font font;
};

#endif
