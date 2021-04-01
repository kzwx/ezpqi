/*
 * my_hunter
 */

#ifndef LAUNCH_SCENE_HPP
#define LAUNCH_SCENE_HPP

#include <string>
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../hunter/Hunter.hpp"
#include "../listeners/MouseListener.hpp"
#include "../widgets/Button.hpp"

class PlayMouseListener : public MouseListener {
    public:
        PlayMouseListener(SceneManager *manager, Button *self);
        virtual ~PlayMouseListener();

        virtual void onMousePressed(int x, int y) override;
        virtual void onMouseReleased(int x, int y) override;

        virtual void onMouseMoved(int x, int y) override;

        virtual void onMouseEntered(int x, int y) override;
        virtual void onMouseExited(int x, int y) override;

    protected:
        SceneManager *manager;
        Button *self;
};

class QuitMouseListener : public MouseListener {
    public:
        QuitMouseListener(Hunter *hunter, Button *self);
        virtual ~QuitMouseListener();

        virtual void onMousePressed(int x, int y) override;
        virtual void onMouseReleased(int x, int y) override;

        virtual void onMouseMoved(int x, int y) override;

        virtual void onMouseEntered(int x, int y) override;
        virtual void onMouseExited(int x, int y) override;

    protected:
        Hunter *hunter;
        Button *self;
};

class LaunchScene : public Scene {
    public:
        LaunchScene(Hunter *hunter, SceneManager *manager);
        virtual ~LaunchScene();

        virtual void onInit() override;
        virtual void onUpdate() override;
        virtual void onDestroy() override;

        virtual std::string getName() override;

    protected:
        Hunter *hunter;
        SceneManager *manager;
};

#endif
