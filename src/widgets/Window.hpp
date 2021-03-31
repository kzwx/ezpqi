/*
 * my_hunter
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Widget.hpp"

class Window : public Widget {
    public:
        Window(std::string title, std::pair<int, int> size);
        virtual ~Window();

        void clear();
        void display();
        void close();

        virtual void draw(sf::IntRect bounds, sf::RenderWindow *window) override;

        void readAndDispatch();
        bool isOpen();


    protected:
        std::pair<int, int> size;

        sf::RenderWindow *window;

};

#endif
