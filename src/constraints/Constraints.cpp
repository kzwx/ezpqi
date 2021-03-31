/*
 * my_hunter
 */

#include <SFML/Graphics.hpp>
#include "Constraints.hpp"
#include "Constraint.hpp"

Constraints::Constraints(
    std::shared_ptr<Constraint> x,
    std::shared_ptr<Constraint> y,
    std::shared_ptr<Constraint> w,
    std::shared_ptr<Constraint> h
) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Constraints::~Constraints() {}

sf::IntRect Constraints::process(sf::IntRect parentBounds) {

    sf::IntRect bounds = sf::IntRect(0, 0, 0, 0);

     bounds.width = this->w->process(
        bounds, parentBounds, ConstraintType::CONSTRAINT_WIDTH
    );

     bounds.height = this->h->process(
        bounds, parentBounds, ConstraintType::CONSTRAINT_HEIGHT
    );

     bounds.left = this->x->process(
        bounds, parentBounds, ConstraintType::CONSTRAINT_X
    );

     bounds.top = this->y->process(
        bounds, parentBounds, ConstraintType::CONSTRAINT_Y
    );

    return (bounds);
}
