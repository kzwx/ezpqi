/*
 * my_hunter
 */

#include <memory>
#include <stdlib.h>
#include <time.h>
#include "hunter/Hunter.hpp"

int main()
{

    srand(time(NULL));

    std::unique_ptr<Hunter> hunter = std::make_unique<Hunter>();

    hunter->init();
    hunter->start();
    hunter->loop();

    return (0);
}
