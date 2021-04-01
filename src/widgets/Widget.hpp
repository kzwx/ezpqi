/*
 * my_hunter
 */

#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <memory>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include "../constraints/Constraints.hpp"
#include "../listeners/FocusListener.hpp"
#include "../listeners/KeyboardListener.hpp"
#include "../listeners/MouseListener.hpp"

class Widget {
    public:
        virtual ~Widget() = default;

        void add(std::shared_ptr<Widget> child, std::shared_ptr<Constraints> constraints);
        void clear();

        void drawAll(sf::IntRect bounds, sf::RenderWindow *window);
        virtual void draw(sf::IntRect bounds, sf::RenderWindow *window) = 0;

        void addFocusListener(FocusListener *listener);
        void addKeyboardListener(KeyboardListener *listener);
        void addMouseListener(MouseListener *listener);

        void propagateEvent(sf::Event event);
        void dispatchEvent(sf::Event event);

    protected:
        sf::IntRect bounds;

        bool isFocused = false;
        bool isMouseOver = false;

        FocusListener *focusListener = nullptr;
        KeyboardListener *keyboardListener = nullptr;
        MouseListener *mouseListener = nullptr;

        std::vector<std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>> children;
};

#endif
