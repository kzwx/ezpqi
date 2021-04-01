/*
 * my_hunter
 */

#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <string>
#include <vector>
#include <memory>
#include "Scene.hpp"
#include "../objects/Duck.hpp"

class GameScene : public Scene {
    public:
        GameScene();
        virtual ~GameScene();

        virtual void onInit() override;
        virtual void onUpdate() override;
        virtual void onDestroy() override;

        void spawn();

        virtual std::string getName() override;

    protected:
        std::shared_ptr<Texture> sheets;
        std::vector<std::shared_ptr<Duck>> ducks;
};

#endif
