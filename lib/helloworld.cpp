#include "helloworld.h"

#include <sstream>

#include "version.h"

::std::string HelloWorld::getVersion()
{
    return PATCH_NUMBER_CONSTANT;
}

::std::string HelloWorld::getText()
{
    ::std::stringstream sstream;
    sstream << "build "<< PATCH_NUMBER_CONSTANT << ::std::endl
            << "Hello, World!" << ::std::endl;
    return sstream.str();
}