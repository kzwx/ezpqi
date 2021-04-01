/*
 * my_hunter
 */

#include <memory>
#include <SFML/Graphics.hpp>
#include "Duck.hpp"
#include "../widgets/Image.hpp"

Duck::Duck(std::shared_ptr<Image> image, std::shared_ptr<AddConstraint> x, std::shared_ptr<AddConstraint> y, int *score) {
    this->image = image;
    this->x = x;
    this->y = y;

    this->image->resize(sf::IntRect(0, 0, 0, 0));
    this->image->addMouseListener(this);

    this->dirx = 3.f;
    this->diry = -2.f;
    this->dirFall = 0;
    this->isFalling = false;
    this->isDead = false;

    int hor = rand() % 5;
    int ver = rand() % 3;

    switch (hor) {
        case 0:
            this->dirx = 2.f;
            break;
        case 1:
            this->dirx = 3.f;
            break;
        case 2:
            this->dirx = 3.5f;
            break;
        case 3:
            this->dirx = 4.f;
            break;
        case 4:
            this->dirx = 5.f;
            break;
    }

    switch (ver) {
        case 0:
            this->diry = -1.f;
            break;
        case 1:
            this->diry = -2.f;
            break;
        case 2:
            this->diry = -2.5f;
            break;
    }

    if (rand() % 2 == 0)
        this->dirx *= -1;

    this->sheetIndex = 0;
    this->tick = 0;

    this->score = score;
}

Duck::~Duck() {}

void Duck::update() {

    this->tick++;

    if (this->isFalling && this->dirFall < 15)
        this->dirFall *= 1.1;

    this->x->add += this->dirx;
    this->y->add += this->diry + this->dirFall;

    if (this->tick % 12 == 0) {
        this->sheetIndex = (this->sheetIndex + 1) % 3;
    }

    if (!this->isFalling)
        this->image->resize(sf::IntRect(0 + 39 * this->sheetIndex, 153, 39, 38));
    else
        this->image->resize(sf::IntRect(0, 231, 36, 36));

    if (this->image->parent == nullptr)
        return;

    if (this->isDead || this->isFalling)
        return;

    if (this->image->bounds.left > this->image->parent->bounds.width || this->image->bounds.left < 0) {
        *(this->score) -= 1;
        this->isDead = true;
    }
}

void Duck::onMousePressed(int x, int y) {
    (void) x;
    (void) y;

    if (this->isFalling)
        return;

    this->isFalling = true;
    this->dirFall = 1.f;

    *(this->score) += 1;
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
