/*
 * my_hunter
 */

#include <memory>
#include "hunter/Hunter.hpp"

int main()
{
    std::unique_ptr<Hunter> hunter = std::make_unique<Hunter>();

    hunter->init();
    hunter->start();
    hunter->loop();

    return (0);
}
