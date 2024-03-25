#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

#include "processor.h"
#include "reader.h"
#include "writer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: bulk N" << std::endl;
        return 1;
    }

    int N = std::stoi(argv[1]);
    Reader reader(std::cin, N);
    Writer writer(std::cout);

    Processor processor;

    reader.registerListener(&processor);
    processor.registerListener(&writer);

    reader.read();
    return 0;
}