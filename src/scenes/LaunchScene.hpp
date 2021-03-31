/*
 * my_hunter
 */

#ifndef LAUNCH_SCENE_HPP
#define LAUNCH_SCENE_HPP

#include <string>
#include "Scene.hpp"

class LaunchScene : public Scene {
    public:
        LaunchScene();
        virtual ~LaunchScene();

        virtual void onInit() override;
        virtual void onUpdate() override;
        virtual void onDestroy() override;

        virtual std::string getName() override;
};

#endif
