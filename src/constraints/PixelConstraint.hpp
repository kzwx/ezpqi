/*
 * my_hunter
 */

#ifndef PIXEL_CONSTRAINT_HPP
#define PIXEL_CONSTRAINT_HPP

#include <SFML/Graphics.hpp>
#include "Constraint.hpp"

class PixelConstraint : public Constraint {
    public:
        PixelConstraint(int value);
        virtual ~PixelConstraint();

        virtual int process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) override;

    protected:
        int value;
};

#endif
