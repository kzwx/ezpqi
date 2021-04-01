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


ContinueMouseListener::ContinueMouseListener(Hunter *hunter, Button *self, Button *other) {
    this->hunter = hunter;
    this->self = self;
    this->other = other;
}

ContinueMouseListener::~ContinueMouseListener() {}

void ContinueMouseListener::onMousePressed(int x, int y) {
    (void) x;
    (void) y;
}

void ContinueMouseListener::onMouseReleased(int x, int y) {
    (void) x;
    (void) y;

    this->hunter->play();

    this->self->setVisibility(false);
    this->other->setVisibility(false);
}

void ContinueMouseListener::onMouseMoved(int x, int y) {
    (void) x;
    (void) y;
}

void ContinueMouseListener::onMouseEntered(int x, int y) {
    this->self->onMouseEntered(x, y);
}

void ContinueMouseListener::onMouseExited(int x, int y) {
    this->self->onMouseExited(x, y);
}



LeftMouseListener::LeftMouseListener(SceneManager *manager, Hunter *hunter, Button *self) {
    this->manager = manager;
    this->hunter = hunter;
    this->self = self;
}

LeftMouseListener::~LeftMouseListener() {}

void LeftMouseListener::onMousePressed(int x, int y) {
    (void) x;
    (void) y;
}

void LeftMouseListener::onMouseReleased(int x, int y) {
    (void) x;
    (void) y;

    this->manager->launch("launch");
    this->hunter->play();
}

void LeftMouseListener::onMouseMoved(int x, int y) {
    (void) x;
    (void) y;
}

void LeftMouseListener::onMouseEntered(int x, int y) {
    this->self->onMouseEntered(x, y);
}

void LeftMouseListener::onMouseExited(int x, int y) {
    this->self->onMouseExited(x, y);
}



GameScene::GameScene(Hunter *hunter, SceneManager *manager) {
    this->hunter = hunter;
    this->manager = manager;
}

GameScene::~GameScene() {}

void GameScene::onInit() {

    std::shared_ptr<Button> continueButton = std::make_shared<Button>("Continue", "./res/fonts/lato.ttf");
    std::shared_ptr<Button> leftButton = std::make_shared<Button>("Left", "./res/fonts/lato.ttf");

    std::shared_ptr<Texture> backgroundTexture = std::make_shared<Texture>("./res/images/background.png", sf::IntRect(0, 0, 1280, 769));
    this->sheets = std::make_shared<Texture>("./res/images/sheet.png", sf::IntRect(0, 0, 375, 267));

    std::shared_ptr<Image> background = std::make_shared<Image>(backgroundTexture);

    this->add(background, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<CoverConstraint>(1280.f, 768.f),
        std::make_shared<CoverConstraint>(1280.f, 768.f)
    ));

    continueButton->addMouseListener(new ContinueMouseListener(this->hunter, continueButton.get(), leftButton.get()));
    leftButton->addMouseListener(new LeftMouseListener(this->manager, this->hunter, leftButton.get()));

    continueButton->setVisibility(false);
    leftButton->setVisibility(false);

    this->continueButton = continueButton;
    this->leftButton = leftButton;

    this->add(continueButton, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), -20 - 60),
        std::make_shared<PixelConstraint>(300),
        std::make_shared<PixelConstraint>(60)
    ));

    this->add(leftButton, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), 20),
        std::make_shared<PixelConstraint>(300),
        std::make_shared<PixelConstraint>(60)
    ));

    this->addKeyboardListener(this);

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

void GameScene::onKeyPressed(char character) {
    (void) character;
}

void GameScene::onGlobalKeyPressed(sf::Keyboard::Key code) {

    if (code == sf::Keyboard::Escape) {
        if (this->hunter->isPaused()) {
            this->hunter->play();
            this->continueButton->setVisibility(false);
            this->leftButton->setVisibility(false);
        }
        else {
            this->hunter->pause();
            this->continueButton->setVisibility(true);
            this->leftButton->setVisibility(true);
        }
    }
}

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
