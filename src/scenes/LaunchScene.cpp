/*
 * my_hunter
 */

#include <string>
#include <memory>
#include "LaunchScene.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/CenterConstraint.hpp"
#include "../constraints/PixelConstraint.hpp"
#include "../widgets/Composite.hpp"

#include "../widgets/Button.hpp"

LaunchScene::LaunchScene() {}

LaunchScene::~LaunchScene() {}

void LaunchScene::onInit() {

    std::shared_ptr<Composite> comp = std::make_shared<Composite>();
    std::shared_ptr<Button> txt = std::make_shared<Button>("hello world", "./res/fonts/lato.ttf");

    comp->setBackground(sf::Color::Yellow);

    this->add(comp, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<PixelConstraint>(200),
        std::make_shared<PixelConstraint>(200)
    ));

    this->add(txt, std::make_shared<Constraints>(
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(200),
        std::make_shared<PixelConstraint>(40)
    ));

}

void LaunchScene::onUpdate() {}

void LaunchScene::onDestroy() {}

std::string LaunchScene::getName() {
    return "launch";
}
