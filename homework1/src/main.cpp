#include <iostream>
#include <cstdlib>

#include "helloworld.h"

int main(int argc, char** argv)
{
    ::std::cout << HelloWorld::getText();
    return EXIT_SUCCESS;
}