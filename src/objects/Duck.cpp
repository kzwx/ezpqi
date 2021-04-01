/*
 * my_hunter
 */

#include <memory>
#include <SFML/Graphics.hpp>
#include "Duck.hpp"
#include "../widgets/Image.hpp"

Duck::Duck(std::shared_ptr<Image> image, std::shared_ptr<AddConstraint> x, std::shared_ptr<AddConstraint> y) {
    this->image = image;
    this->x = x;
    this->y = y;

    this->image->resize(sf::IntRect(0, 0, 40, 40));
    this->image->addMouseListener(this);

    this->dirx = 3.f;
    this->diry = -2.f;
    this->dirFall = 0;
    this->isFalling = false;
}

Duck::~Duck() {}

void Duck::update() {

    if (this->isFalling && this->dirFall < 15)
        this->dirFall *= 1.1;

    this->x->add += this->dirx;
    this->y->add += this->diry + this->dirFall;
}

void Duck::onMousePressed(int x, int y) {
    (void) x;
    (void) y;

    if (this->isFalling)
        return;

    this->isFalling = true;
    this->dirFall = 1.f;
}

void Duck::onMouseReleased(int x, int y) {
    (void) x;
    (void) y;
}

void Duck::onMouseMoved(int x, int y) {
    (void) x;
    (void) y;
}

void Duck::onMouseEntered(int x, int y) {
    (void) x;
    (void) y;
}

void Duck::onMouseExited(int x, int y) {
    (void) x;
    (void) y;
}
