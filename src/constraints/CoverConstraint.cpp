/*
 * my_hunter
 */

#include <SFML/Graphics.hpp>
#include "CoverConstraint.hpp"

CoverConstraint::CoverConstraint(float width, float height) {
    this->width = width;
    this->height = height;
}

CoverConstraint::~CoverConstraint() {}

int CoverConstraint::process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) {
    (void) selfBounds;

    float ratio = this->width / this->height;
    float parentRatio = (float) parentBounds.width / parentBounds.height;

    if (parentRatio > ratio) {

        if (type == ConstraintType::CONSTRAINT_WIDTH)
            return parentBounds.width;

        else if (type == ConstraintType::CONSTRAINT_HEIGHT)
            return parentBounds.width / ratio;
    }

    else {

        if (type == ConstraintType::CONSTRAINT_WIDTH)
            return parentBounds.height * ratio;

        else if (type == ConstraintType::CONSTRAINT_HEIGHT)
            return parentBounds.height;
    }

    return (0);
}
