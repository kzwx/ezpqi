/*
 * my_hunter
 */

#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <string>
#include <vector>
#include <memory>
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../hunter/Hunter.hpp"
#include "../objects/Duck.hpp"
#include "../listeners/KeyboardListener.hpp"
#include "../widgets/Image.hpp"
#include "../widgets/Button.hpp"

class ContinueMouseListener : public MouseListener {
    public:
        ContinueMouseListener(Hunter *hunter, Button *self, Button *other);
        virtual ~ContinueMouseListener();

        virtual void onMousePressed(int x, int y) override;
        virtual void onMouseReleased(int x, int y) override;

        virtual void onMouseMoved(int x, int y) override;

        virtual void onMouseEntered(int x, int y) override;
        virtual void onMouseExited(int x, int y) override;

    protected:
        Hunter *hunter;
        Button *self;
        Button *other;
};

class LeftMouseListener : public MouseListener {
    public:
        LeftMouseListener(SceneManager *manager, Hunter *hunter, Button *self);
        virtual ~LeftMouseListener();

        virtual void onMousePressed(int x, int y) override;
        virtual void onMouseReleased(int x, int y) override;

        virtual void onMouseMoved(int x, int y) override;

        virtual void onMouseEntered(int x, int y) override;
        virtual void onMouseExited(int x, int y) override;

    protected:
        SceneManager *manager;
        Hunter *hunter;
        Button *self;
};
class GameScene : public Scene, public KeyboardListener {
    public:
        GameScene(Hunter *hunter, SceneManager *manager);
        virtual ~GameScene();

        virtual void onInit() override;
        virtual void onUpdate() override;
        virtual void onDestroy() override;

        virtual void onKeyPressed(char character) override;
        virtual void onGlobalKeyPressed(sf::Keyboard::Key code) override;

        void spawn();

        virtual std::string getName() override;

        std::shared_ptr<Button> continueButton;
        std::shared_ptr<Button> leftButton;
        std::shared_ptr<Button> messageBoxLoose;
        std::shared_ptr<Button> messageBoxWin;
    protected:
        Hunter *hunter;
        SceneManager *manager;

        std::shared_ptr<Texture> sheets;
        std::vector<std::shared_ptr<Duck>> ducks;

        std::shared_ptr<AddConstraint> xWave;
        std::shared_ptr<AddConstraint> wWave;

        int score;
        float scoreF;
};

#endif
