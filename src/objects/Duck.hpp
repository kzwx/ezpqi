/*
 * my_hunter
 */

#ifndef DUCK_HPP
#define DUCK_HPP

#include <memory>
#include "../constraints/AddConstraint.hpp"
#include "../listeners/MouseListener.hpp"
#include "../widgets/Image.hpp"

class Duck : public MouseListener {
    public:
        Duck(std::shared_ptr<Image> image, std::shared_ptr<AddConstraint> x, std::shared_ptr<AddConstraint> y);
        virtual ~Duck();

        void update();

        virtual void onMousePressed(int x, int y) override;
        virtual void onMouseReleased(int x, int y) override;

        virtual void onMouseMoved(int x, int y) override;

        virtual void onMouseEntered(int x, int y) override;
        virtual void onMouseExited(int x, int y) override;

    protected:
        std::shared_ptr<Image> image;
        std::shared_ptr<AddConstraint> x;
        std::shared_ptr<AddConstraint> y;

        bool isFalling;

        float dirx;
        float diry;
        float dirFall;
};

#endif
