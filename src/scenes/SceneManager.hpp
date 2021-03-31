/*
 * my_hunter
 */

#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <string>
#include <memory>
#include <vector>
#include "Scene.hpp"
#include "../widgets/Widget.hpp"

class SceneManager {
    public:
        SceneManager(std::shared_ptr<Widget> container);
        virtual ~SceneManager();

        void update();
        void launch(std::string name);

        void registerScene(std::shared_ptr<Scene> scene);

    protected:
        std::shared_ptr<Widget> container;
        std::shared_ptr<Scene> current;

        std::map<std::string, std::shared_ptr<Scene>> scenes;
};

#endif
