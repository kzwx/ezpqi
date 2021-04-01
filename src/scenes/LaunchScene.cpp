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
#include "../widgets/Image.hpp"
#include "../widgets/Texture.hpp"

LaunchScene::LaunchScene() {}

LaunchScene::~LaunchScene() {}

void LaunchScene::onInit() {

    std::shared_ptr<Composite> comp = std::make_shared<Composite>();
    std::shared_ptr<Button> txt = std::make_shared<Button>("hello world", "./res/fonts/lato.ttf");

    std::shared_ptr<Texture> texture = std::make_shared<Texture>("./res/images/ducks.png", sf::IntRect(0, 0, 40, 40));
    std::shared_ptr<Image> image = std::make_shared<Image>(texture);

    comp->setBackground(sf::Color::Yellow);

    this->add(comp, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<PixelConstraint>(200),
        std::make_shared<PixelConstraint>(200)
    ));

    this->add(image, std::make_shared<Constraints>(
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(40),
        std::make_shared<PixelConstraint>(40)
    ));

}

void LaunchScene::onUpdate() {}

void LaunchScene::onDestroy() {}

std::string LaunchScene::getName() {
    return "launch";
}
