/*
 * my_hunter
 */

#include <SFML/Graphics.hpp>
#include "CenterConstraint.hpp"

CenterConstraint::CenterConstraint() {}

CenterConstraint::~CenterConstraint() {}

int CenterConstraint::process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) {

    if (type == ConstraintType::CONSTRAINT_X)
        return parentBounds.left + (parentBounds.width / 2 - selfBounds.width / 2);

    if (type == ConstraintType::CONSTRAINT_Y)
        return parentBounds.top + (parentBounds.height / 2 - selfBounds.height / 2);

    return 0;
}
