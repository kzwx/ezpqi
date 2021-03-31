/*
 * my_hunter
 */

#ifndef CENTER_CONSTRAINT_HPP
#define CENTER_CONSTRAINT_HPP

#include <SFML/Graphics.hpp>
#include "Constraint.hpp"

class CenterConstraint : public Constraint {
    public:
        CenterConstraint();
        virtual ~CenterConstraint();

        virtual int process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) override;
};

#endif
