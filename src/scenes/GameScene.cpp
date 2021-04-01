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
#include "../widgets/Text.hpp"
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
    this->score = 50;
    this->scoreF = 0.5f;
}

GameScene::~GameScene() {}

void GameScene::onInit() {

    std::shared_ptr<Button> continueButton = std::make_shared<Button>("Continue", "./res/fonts/lato.ttf");
    std::shared_ptr<Button> leftButton = std::make_shared<Button>("Left", "./res/fonts/lato.ttf");
    std::shared_ptr<Text> messageBoxLoose = std::make_shared<Text>("Vous avez perdu, retentez votre chance", "./res/fonts/lato.ttf");
    std::shared_ptr<Text> messageBoxWin = std::make_shared<Text>("Vous avez reussi a passer toutes les epreuves,\nnous avons besoins de votre talent\nenvoyer une candidature a marseille@epitech.eu\npour commencer tres prochainement la selection", "./res/fonts/lato.ttf");
    messageBoxLoose->setForeground(sf::Color::White);
    messageBoxWin->setForeground(sf::Color::White);

    std::shared_ptr<Texture> backgroundTexture = std::make_shared<Texture>("./res/images/background.png", sf::IntRect(0, 0, 1280, 769));
    this->sheets = std::make_shared<Texture>("./res/images/sheet.png", sf::IntRect(0, 0, 375, 267));

    std::shared_ptr<Texture> waveTexture = std::make_shared<Texture>("./res/images/wave.png", sf::IntRect(0, 0, 364, 20));
    std::shared_ptr<Image> wave1 = std::make_shared<Image>(waveTexture);
    std::shared_ptr<Image> wave2 = std::make_shared<Image>(waveTexture);

    wave1->resize(sf::IntRect(0, 0, 364, 10));
    wave2->resize(sf::IntRect(0, 10, 364, 10));

    std::shared_ptr<Image> background = std::make_shared<Image>(backgroundTexture);

    this->add(background, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<CoverConstraint>(1280.f, 768.f),
        std::make_shared<CoverConstraint>(1280.f, 768.f)
    ));

    this->add(wave1, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<PixelConstraint>(20),
        std::make_shared<PixelConstraint>(364),
        std::make_shared<PixelConstraint>(10)
    ));

    this->xWave = std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), 0);
    this->wWave = std::make_shared<AddConstraint>(std::make_shared<PixelConstraint>(364), 0);

    this->add(wave2, std::make_shared<Constraints>(
        this->xWave,
        std::make_shared<PixelConstraint>(20),
        this->wWave,
        std::make_shared<PixelConstraint>(10)
    ));

    continueButton->addMouseListener(new ContinueMouseListener(this->hunter, continueButton.get(), leftButton.get()));
    leftButton->addMouseListener(new LeftMouseListener(this->manager, this->hunter, leftButton.get()));

    continueButton->setVisibility(false);
    leftButton->setVisibility(false);
    messageBoxLoose->setVisibility(false);
    messageBoxWin->setVisibility(false);

    this->continueButton = continueButton;
    this->leftButton = leftButton;
    this->messageBoxLoose = messageBoxLoose;
    this->messageBoxWin = messageBoxWin;

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

    this->add(messageBoxLoose, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<AddConstraint>(std::make_shared<CenterConstraint>(), -20 - 80),
        std::make_shared<PixelConstraint>(300),
        std::make_shared<PixelConstraint>(80)
    ));

    this->add(messageBoxWin, std::make_shared<Constraints>(
        std::make_shared<CenterConstraint>(),
        std::make_shared<CenterConstraint>(),
        std::make_shared<PixelConstraint>(500),
        std::make_shared<PixelConstraint>(120)
    ));

    this->addKeyboardListener(this);

    this->score = 50;
    this->scoreF = 0.5f;
}

void GameScene::onUpdate() {

    std::vector<std::shared_ptr<Duck>>::iterator it = this->ducks.begin();
    std::vector<std::shared_ptr<Duck>>::iterator end = this->ducks.end();

    while (it != end) {

        std::shared_ptr<Duck> duck = *it;

        duck->update();

        it++;
    }

    if (rand() % 30 == 0)
        this->spawn();

    if (0 <= this->score && this->score <= 100)
        this->scoreF = (float) this->score / 100.0f;

    this->xWave->add = (364 * this->scoreF - 364) / 2;
    this->wWave->add = 364 * this->scoreF - 364;

    if (this->score <= 0 || this->score >= 100) {

        std::vector<std::shared_ptr<Duck>>::iterator it2 = this->ducks.begin();
        std::vector<std::shared_ptr<Duck>>::iterator end2 = this->ducks.end();

        while (it2 != end2) {

            std::shared_ptr<Duck> duck2 = *it2;

            duck2->image->setVisibility(false);

            it2++;
        }
    }

    if (this->score <= 0) {
        this->messageBoxLoose->setVisibility(true);
        this->hunter->pause();
        this->leftButton->setVisibility(true);
    }

    if (this->score >= 100) {
        this->messageBoxWin->setVisibility(true);
        this->hunter->pause();
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

    std::shared_ptr<Duck> duck = std::make_shared<Duck>(image, x, y, &(this->score));

    this->ducks.push_back(duck);

    std::shared_ptr<Constraints> constraints = std::make_shared<Constraints>(
        x, y,
        std::make_shared<PixelConstraint>(80),
        std::make_shared<PixelConstraint>(80)
    );

    this->add(image, constraints);
}

std::string GameScene::getName() {
    return "game";
}
