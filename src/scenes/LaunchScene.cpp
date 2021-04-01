/*
 * my_hunter
 */

#include <string>
#include <memory>
#include "LaunchScene.hpp"
#include "SceneManager.hpp"
#include "../constraints/Constraints.hpp"
#include "../constraints/AddConstraint.hpp"
#include "../constraints/CenterConstraint.hpp"
#include "../constraints/CoverConstraint.hpp"
#include "../constraints/PixelConstraint.hpp"
#include "../widgets/Button.hpp"
#include "../widgets/Image.hpp"
#include "../widgets/Texture.hpp"
#include "../hunter/Hunter.hpp"

PlayMouseListener::PlayMouseListener(SceneManager *manager, Button *self) {
    this->manager = manager;
    this->self = self;
}

PlayMouseListener::~PlayMouseListener() {}

void PlayMouseListener::onMousePressed(int x, int y) {
    (void) x;
    (void) y;
}

void PlayMouseListener::onMouseReleased(int x, int y) {
    (void) x;
    (void) y;

    this->manager->launch("game");
}

void PlayMouseListener::onMouseMoved(int x, int y) {
    (void) x;
    (void) y;
}

void PlayMouseListener::onMouseEntered(int x, int y) {
    this->self->onMouseEntered(x, y);
}

void PlayMouseListener::onMouseExited(int x, int y) {
    this->self->onMouseExited(x, y);
}



QuitMouseListener::QuitMouseListener(Hunter *hunter, Button *self) {
    this->hunter = hunter;
    this->self = self;
}

QuitMouseListener::~QuitMouseListener() {}

void QuitMouseListener::onMousePressed(int x, int y) {
    (void) x;
    (void) y;
}

void QuitMouseListener::onMouseReleased(int x, int y) {
    (void) x;
    (void) y;

    this->hunter->stop();
}

void QuitMouseListener::onMouseMoved(int x, int y) {
    (void) x;
    (void) y;
}

void QuitMouseListener::onMouseEntered(int x, int y) {
    this->self->onMouseEntered(x, y);
}

void QuitMouseListener::onMouseExited(int x, int y) {
    this->self->onMouseExited(x, y);
}


LaunchScene::LaunchScene(Hunter *hunter, SceneManager *manager) {
    this->hunter = hunter;
    this->manager = manager;
}

LaunchScene::~LaunchScene() {}

void LaunchScene::onInit() {

    std::shared_ptr<Button> playButton = std::make_shared<Button>("Play", "./res/fonts/lato.ttf");
    std::shared_ptr<Button> quitButton = std::make_shared<Button>("Quit", "./res/fonts/lato.ttf");

    std::shared_ptr<Texture> backgroundTexture = std::make_shared<Texture>("./res/images/background.png", sf::IntRect(0, 0, 1280, 769));
    std::shared_ptr<Image> background = std::make_shared<Image>(backgroundTexture);

    this->add(background, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<CoverConstraint>(1280.f, 768.f),
        std::make_shared<CoverConstraint>(1280.f, 768.f)
    ));

    playButton->addMouseListener(new PlayMouseListener(this->manager, playButton.get()));
    quitButton->addMouseListener(new QuitMouseListener(this->hunter, quitButton.get()));

    this->add(playButton, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), -20 - 60),
        std::make_shared<PixelConstraint>(300),
        std::make_shared<PixelConstraint>(60)
    ));

    this->add(quitButton, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), 20),
        std::make_shared<PixelConstraint>(300),
        std::make_shared<PixelConstraint>(60)
    ));

}

void LaunchScene::onUpdate() {}

void LaunchScene::onDestroy() {}

std::string LaunchScene::getName() {
    return "launch";
}
