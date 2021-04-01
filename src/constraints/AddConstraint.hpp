/*
 * my_hunter
 */

#ifndef ADD_CONSTRAINT_HPP
#define ADD_CONSTRAINT_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "Constraint.hpp"

class AddConstraint : public Constraint {
    public:
        AddConstraint(std::shared_ptr<Constraint> constraint, int add);
        virtual ~AddConstraint();

        virtual int process(sf::IntRect selfBounds, sf::IntRect parentBounds, ConstraintType type) override;

        int add;
    protected:
        std::shared_ptr<Constraint> constraint;
};

#endif
