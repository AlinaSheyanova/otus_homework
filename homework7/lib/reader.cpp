#include "reader.h"

#include <iostream>
#include <algorithm>

Reader::Reader(std::istream& input, int n) : input(input),  N(n) {}

void Reader::registerListener(IListener* listener) {
    listeners.push_back(listener);
}

void Reader::removeListener(IListener* listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void Reader::notifyListeners(const std::vector<std::string>& block) {
    for (IListener *listener: listeners)
        listener->onNewBlock(block);
}

void Reader::read() {
    std::string line;
    std::vector<std::string> commands;
    int dynamic_block_level = 0;
    while (std::getline(input, line)) {
        if (line == "{") {
            if (dynamic_block_level == 0 && !commands.empty()) {
                notifyListeners(commands);
                commands.clear();
            }
            dynamic_block_level++;
        } else if (line == "}") {
            dynamic_block_level--;
            if (dynamic_block_level == 0) {
                notifyListeners(commands);
                commands.clear();
            }
        } else {
            commands.push_back(line);
            if (dynamic_block_level == 0 && commands.size() == N) {
                notifyListeners(commands);
                commands.clear();
            }
        }
    }
    if (!commands.empty() && dynamic_block_level == 0) {
        notifyListeners(commands);
    } else if (dynamic_block_level > 0) {
        std::cout << "Warning: mismatched block delimiters!" << std::endl;
    }
}