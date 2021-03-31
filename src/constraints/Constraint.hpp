/*
 * my_hunter
 */

#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <SFML/Graphics.hpp>

enum ConstraintType {
    CONSTRAINT_X,
    CONSTRAINT_Y,
    CONSTRAINT_WIDTH,
    CONSTRAINT_HEIGHT
};

class Constraint {
    public:
        virtual ~Constraint() = default;

        virtual int process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) = 0;
};

#endif
