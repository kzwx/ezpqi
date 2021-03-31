/*
 * my_hunter
 */

#include <SFML/Graphics.hpp>
#include "RelativeConstraint.hpp"

RelativeConstraint::RelativeConstraint(float percent) {
    this->percent = percent;
}

RelativeConstraint::~RelativeConstraint() {}

int RelativeConstraint::process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) {
    (void) selfBounds;

    switch (type) {
        case ConstraintType::CONSTRAINT_X:
        case ConstraintType::CONSTRAINT_WIDTH:
            return parentBounds.width * this->percent;

        case ConstraintType::CONSTRAINT_Y:
        case ConstraintType::CONSTRAINT_HEIGHT:
            return parentBounds.height * this->percent;
    }

    return 0;
}
