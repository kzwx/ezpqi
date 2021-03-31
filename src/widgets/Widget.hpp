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

typedef void (*MousePressedListener)(int x, int y);
typedef void (*MouseReleasedListener)(int x, int y);
typedef void (*MouseMovedListener)(int x, int y);
typedef void (*MouseEnteredListener)(int x, int y);
typedef void (*MouseExitedListener)(int x, int y);
typedef void (*FocusedInListener)();
typedef void (*FocusedOutListener)();
typedef void (*KeyPressedListener)(char character);

class Widget {
    public:
        virtual ~Widget() = default;

        void add(std::shared_ptr<Widget> child, std::shared_ptr<Constraints> constraints);

        void drawAll(sf::IntRect bounds, sf::RenderWindow *window);
        virtual void draw(sf::IntRect bounds, sf::RenderWindow *window) = 0;

        void addMousePressedListener(MousePressedListener listener);
        void addMouseReleasedListener(MouseReleasedListener listener);
        void addMouseMovedListener(MouseMovedListener listener);
        void addMouseEnteredListener(MouseEnteredListener listener);
        void addMouseExitedListener(MouseExitedListener listener);
        void addFocusedInListener(FocusedInListener listener);
        void addFocusedOutListener(FocusedOutListener listener);
        void addKeyPressedListener(KeyPressedListener listener);

        void propagateEvent(sf::Event event);
        void dispatchEvent(sf::Event event);

    protected:
        sf::IntRect bounds;

        bool isFocused = false;
        bool isMouseOver = false;

        MousePressedListener mousePressedListener = nullptr;
        MouseReleasedListener mouseReleasedListener = nullptr;
        MouseMovedListener mouseMovedListener = nullptr;
        MouseEnteredListener mouseEnteredListener = nullptr;
        MouseExitedListener mouseExitedListener = nullptr;
        FocusedInListener focusedInListener = nullptr;
        FocusedOutListener focusedOutListener = nullptr;
        KeyPressedListener keyPressedListener = nullptr;

        std::vector<std::pair<std::shared_ptr<Constraints>, std::shared_ptr<Widget>>> children;
};

#endif
