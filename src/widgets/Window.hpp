/*
 * my_hunter
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Widget.hpp"

class Window : public Widget {
    public:
        Window(std::string title);
        virtual ~Window();

        void clear();
        void display();
        void close();

        void readAndDispatch();
        bool isOpen();


    protected:
        sf::RenderWindow *window;
};

#endif
