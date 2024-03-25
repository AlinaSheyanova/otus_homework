#include "processor.h"

#include <algorithm>

Processor::Processor() {}

void Processor::onNewBlock(const std::vector<std::string>& block) {
    commands = block;
    notifyListeners(commands);
    commands.clear();
}

void Processor::registerListener(IListener* listener) {
    listeners.push_back(listener);
}

void Processor::removeListener(IListener* listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void Processor::notifyListeners(const std::vector<std::string>& block) {
    for (IListener *listener: listeners)
        listener->onNewBlock(block);
}