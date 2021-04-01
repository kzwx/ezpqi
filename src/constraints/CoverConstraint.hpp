/*
 * my_hunter
 */

#ifndef COVER_CONSTRAINT_HPP
#define COVER_CONSTRAINT_HPP

#include <SFML/Graphics.hpp>
#include "Constraint.hpp"

class CoverConstraint : public Constraint {
    public:
        CoverConstraint(float width, float height);
        virtual ~CoverConstraint();

        virtual int process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) override;

    protected:
        float width;
        float height;
};

#endif
