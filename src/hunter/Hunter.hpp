/*
 * my_hunter
 */

#ifndef MY_HUNTER_HPP
#define MY_HUNTER_HPP

#include <memory>
#include "../scenes/SceneManager.hpp"
#include "../widgets/Window.hpp"

class Hunter {
    public:
        Hunter();
        virtual ~Hunter();

        void init();
        void start();
        void play();
        void pause();
        void loop();
        void stop();
        void exit();

    protected:
        void update();
        void render();

        bool running;
        bool playing;

        std::unique_ptr<SceneManager> scenesManager;

        std::unique_ptr<Window> window;
};

#endif
