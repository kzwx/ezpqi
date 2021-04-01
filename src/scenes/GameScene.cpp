/*
 * my_hunter
 */

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameScene.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/AddConstraint.hpp"
#include "../constraints/CenterConstraint.hpp"
#include "../constraints/CoverConstraint.hpp"
#include "../constraints/PixelConstraint.hpp"
#include "../constraints/RelativeConstraint.hpp"
#include "../objects/Duck.hpp"
#include "../widgets/Image.hpp"
#include "../widgets/Texture.hpp"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::onInit() {

    std::shared_ptr<Texture> backgroundTexture = std::make_shared<Texture>("./res/images/background.png", sf::IntRect(0, 0, 1280, 769));
    this->sheets = std::make_shared<Texture>("./res/images/sheet.png", sf::IntRect(0, 0, 375, 267));

    std::shared_ptr<Image> background = std::make_shared<Image>(backgroundTexture);

    this->add(background, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<CoverConstraint>(1280.f, 768.f),
        std::make_shared<CoverConstraint>(1280.f, 768.f)
    ));

    this->spawn();
}

void GameScene::onUpdate() {

    std::vector<std::shared_ptr<Duck>>::iterator it = this->ducks.begin();
    std::vector<std::shared_ptr<Duck>>::iterator end = this->ducks.end();

    while (it != end) {

        std::shared_ptr<Duck> duck = *it;

        duck->update();

        it++;
    }

}

void GameScene::onDestroy() {}

void GameScene::spawn() {

    std::shared_ptr<Image> image = std::make_shared<Image>(this->sheets);

    std::shared_ptr<AddConstraint> x = std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), 0);
    std::shared_ptr<AddConstraint> y = std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), 0);

    std::shared_ptr<Duck> duck = std::make_shared<Duck>(image, x, y);

    this->ducks.push_back(duck);

    std::shared_ptr<Constraints> constraints = std::make_shared<Constraints>(
        x, y,
        std::make_shared<PixelConstraint>(60),
        std::make_shared<PixelConstraint>(60)
    );

    this->add(image, constraints);
}

std::string GameScene::getName() {
    return "game";
}
