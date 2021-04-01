/*
 * my_hunter
 */

#include <memory>
#include <SFML/Graphics.hpp>
#include "AddConstraint.hpp"
#include "Constraint.hpp"

AddConstraint::AddConstraint(std::shared_ptr<Constraint> constraint, int add) {
    this->constraint = constraint;
    this->add = add;
}

AddConstraint::~AddConstraint() {}

int AddConstraint::process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) {
    return this->constraint->process(selfBounds, parentBounds, type) + add;
}
