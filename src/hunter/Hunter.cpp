/*
 * my_hunter
 */

#include <memory>
#include <utility>
#include "Hunter.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/PixelConstraint.hpp"
#include "../constraints/RelativeConstraint.hpp"
#include "../scenes/SceneManager.hpp"
#include "../scenes/GameScene.hpp"
#include "../scenes/LaunchScene.hpp"
#include "../widgets/Composite.hpp"
#include "../widgets/Window.hpp"

Hunter::Hunter() {

    this->running = false;
    this->playing = false;

}

Hunter::~Hunter() {}

void Hunter::init() {

    this->window = std::make_unique<Window>("My Hunter", std::pair<int, int>(800, 600));

    std::shared_ptr<Composite> container = std::make_shared<Composite>();

    this->scenesManager = std::make_shared<SceneManager>(container);

    this->scenesManager->registerScene(std::make_shared<LaunchScene>(this, this->scenesManager.get()));
    this->scenesManager->registerScene(std::make_shared<GameScene>(this, this->scenesManager.get()));

    this->scenesManager->launch("launch");

    this->window->add(container, std::make_shared<Constraints>(
        std::make_shared<PixelConstraint>(0),
        std::make_shared<PixelConstraint>(0),
        std::make_shared<RelativeConstraint>(1.0f),
        std::make_shared<RelativeConstraint>(1.0f)
    ));

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

    sf::Clock clock;

    int last_tick = 0;
    int tick_time = 1000000 / 60;

    while (this->running) {

        this->window->readAndDispatch();

        if (clock.getElapsedTime().asMicroseconds() - last_tick > tick_time) {

            this->update();

            last_tick += tick_time;
        }

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

bool Hunter::isPaused() {
    return !this->playing;
}

void Hunter::update() {

    if (!this->playing)
        return;

    this->scenesManager->update();
}

void Hunter::render() {
    this->window->clear();
    this->window->display();
}
