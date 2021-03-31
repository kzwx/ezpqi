/*
 * my_hunter
 */

#ifndef CONSTRAINTS_HPP
#define CONSTRAINTS_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "Constraint.hpp"

class Constraints {
    public:
        Constraints(
            std::shared_ptr<Constraint> x,
            std::shared_ptr<Constraint> y,
            std::shared_ptr<Constraint> w,
            std::shared_ptr<Constraint> h
        );
        virtual ~Constraints();

        sf::IntRect process(sf::IntRect parentBounds);

    protected:
        std::shared_ptr<Constraint> x;
        std::shared_ptr<Constraint> y;
        std::shared_ptr<Constraint> w;
        std::shared_ptr<Constraint> h;
};

#endif
