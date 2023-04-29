#include <iostream>
#include <cstdlib>
#include "version.h"

int main(int argc, char** argv)
{
    ::std::cout << PATCH_NUMBER_CONSTANT << ::std::endl;
    ::std::cout << "Hello World!" << ::std::endl;
    return EXIT_SUCCESS;
}