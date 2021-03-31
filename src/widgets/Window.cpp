/*
 * my_hunter
 */

#include <string>
#include <memory>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

Window::Window(std::string title, std::pair<int, int> size) {

    this->window = new sf::RenderWindow(
        sf::VideoMode(800, 768),
        title
    );

    this->window->setFramerateLimit(80);

    this->size = size;
}

Window::~Window() {
    delete this->window;
}

void Window::display() {

    this->drawAll(sf::IntRect(
        0, 0, this->size.first, this->size.second
    ), this->window);

    this->window->display();
}

void Window::clear() {
    this->window->clear();
}

void Window::close() {
    this->window->close();
}

void Window::draw(sf::IntRect bounds, sf::RenderWindow *window) {
    (void) bounds;
    (void) window;
}

void Window::readAndDispatch() {

    sf::Event event;

    while (this->window->pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            this->window->close();
        }

        if (event.type == sf::Event::Resized) {

            this->size.first = event.size.width;
            this->size.second = event.size.height;

            this->window->setView(sf::View(sf::FloatRect(
                0, 0,
                event.size.width, event.size.height
            )));

        }
    }
}

bool Window::isOpen() {
    return this->window->isOpen();
}
