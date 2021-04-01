/*
 * my_hunter
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Composite.hpp"
#include "Text.hpp"
#include "../listeners/MouseListener.hpp"

class Button : public Composite, public MouseListener {
    public:
        Button(std::string content, std::string fontPath);
        virtual ~Button();

        virtual void onMousePressed(int x, int y) override;
        virtual void onMouseReleased(int x, int y) override;

        virtual void onMouseMoved(int x, int y) override;

        virtual void onMouseEntered(int x, int y) override;
        virtual void onMouseExited(int x, int y) override;

    protected:
        std::shared_ptr<Text> text;
};

#endif
