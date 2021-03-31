/*
 * my_hunter
 */

#include <string>
#include <memory>
#include <utility>
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../widgets/Widget.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/PixelConstraint.hpp"
#include "../constraints/RelativeConstraint.hpp"

SceneManager::SceneManager(std::shared_ptr<Widget> container) {

    this->container = container;
    this->current = nullptr;

}

SceneManager::~SceneManager() {

    if (this->current != nullptr)
        this->current->onDestroy();

}

void SceneManager::update() {

    if (this->current == nullptr)
        return;

    this->current->onUpdate();
}

void SceneManager::launch(std::string name) {


    if (this->current != nullptr)
        this->current->onDestroy();

    this->current = this->scenes[name];

    this->current->onInit();

    this->container->clear();
    this->container->add(
        current,
        std::make_shared<Constraints>(
            std::make_shared<PixelConstraint>(0),
            std::make_shared<PixelConstraint>(0),
            std::make_shared<RelativeConstraint>(1.0f),
            std::make_shared<RelativeConstraint>(1.0f)
        )
    );

}

void SceneManager::registerScene(std::shared_ptr<Scene> scene) {
    this->scenes[scene->getName()] = scene;
}
