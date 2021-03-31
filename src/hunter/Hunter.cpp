/*
 * my_hunter
 */

#include <memory>
#include <utility>
#include "Hunter.hpp"
#include "../widgets/Window.hpp"

Hunter::Hunter() {

    this->running = false;
    this->playing = false;

}

Hunter::~Hunter() {}

void Hunter::init() {

    this->window = std::make_unique<Window>("My Hunter", std::pair<int, int>(800, 600));

}

void Hunter::start() {

    this->running = true;
    this->playing = true;

}

void Hunter::play() {
    this->playing = true;
}

void Hunter::pause() {
    this->playing = false;
}

void Hunter::loop() {

    while (this->running) {

        this->window->readAndDispatch();

        this->update();
        this->render();

        if (!this->window->isOpen())
            this->stop();
    }

    this->exit();
}

void Hunter::stop() {
    this->running = false;
    this->playing = false;
}

void Hunter::exit() {

}

void Hunter::update() {

    if (!this->playing)
        return;

}

void Hunter::render() {
    this->window->clear();
    this->window->display();
}
