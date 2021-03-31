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

    this->scenesManager = std::make_unique<SceneManager>(container);

    this->scenesManager->registerScene(std::make_shared<LaunchScene>());

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

    this->scenesManager->update();
}

void Hunter::render() {
    this->window->clear();
    this->window->display();
}
