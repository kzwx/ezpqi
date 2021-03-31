/*
 * my_hunter
 */

#include <string>
#include <memory>
#include "LaunchScene.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/PixelConstraint.hpp"
#include "../widgets/Composite.hpp"

LaunchScene::LaunchScene() {}

LaunchScene::~LaunchScene() {}

void LaunchScene::onInit() {

    std::shared_ptr<Composite> comp = std::make_shared<Composite>();

    comp->setBackground(sf::Color::Yellow);

    this->add(comp, std::make_shared<Constraints>(
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(20)
    ));

}

void LaunchScene::onUpdate() {}

void LaunchScene::onDestroy() {}

std::string LaunchScene::getName() {
    return "launch";
}
