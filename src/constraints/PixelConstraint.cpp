/*
 * my_hunter
 */

#include <SFML/Graphics.hpp>
#include "PixelConstraint.hpp"

PixelConstraint::PixelConstraint(int value) {
    this->value = value;
}

PixelConstraint::~PixelConstraint() {}

int PixelConstraint::process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) {
    (void) selfBounds;

    if (type == ConstraintType::CONSTRAINT_X)
        return parentBounds.left + this->value;

    if (type == ConstraintType::CONSTRAINT_Y)
        return parentBounds.top + this->value;

    return this->value;
}
