/*
 * my_hunter
 */

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

Window::Window(std::string title) {

    this->window = new sf::RenderWindow(
        sf::VideoMode(800, 768),
        title
    );

    this->window->setFramerateLimit(80);

}

Window::~Window() {}

void Window::display() {
    this->window->display();
}

void Window::clear() {
    this->window->clear();
}

void Window::close() {
    this->window->close();
}

void Window::readAndDispatch() {

    sf::Event event;

    while (this->window->pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            this->window->close();
        }

        if (event.type == sf::Event::Resized) {

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
