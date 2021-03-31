/*
 * my_hunter
 */

#ifndef RELATIVE_CONSTRAINT_HPP
#define RELATIVE_CONSTRAINT_HPP

#include <SFML/Graphics.hpp>
#include "Constraint.hpp"

class RelativeConstraint : public Constraint {
    public:
        RelativeConstraint(float percent);
        virtual ~RelativeConstraint();

        virtual int process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) override;

    protected:
        float percent;
};

#endif
