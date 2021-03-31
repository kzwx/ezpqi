/*
 * my_hunter
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include "../widgets/Composite.hpp"

class Scene : public Composite {
    public:
        virtual ~Scene() = default;

        virtual void onInit() = 0;
        virtual void onUpdate() = 0;
        virtual void onDestroy() = 0;

        virtual std::string getName() = 0;
};

#endif
