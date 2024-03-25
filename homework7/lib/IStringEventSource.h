//
// Created by Lina1 on 25.03.2024.
//

#ifndef BULKPROJECT_ISTRINGEVENTSOURCE_H
#define BULKPROJECT_ISTRINGEVENTSOURCE_H

#include "IListener.h"

struct IStringEventSource {
    virtual ~IStringEventSource() = default;
    virtual void registerListener(IListener* listener) = 0;
    virtual void removeListener(IListener* listener) = 0;
    virtual void notifyListeners(const std::vector<std::string>& block) = 0;
};

#endif //BULKPROJECT_ISTRINGEVENTSOURCE_H
