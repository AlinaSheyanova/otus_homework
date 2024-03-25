//
// Created by Lina1 on 25.03.2024.
//

#ifndef BULKPROJECT_ILISTENER_H
#define BULKPROJECT_ILISTENER_H

#include <vector>
#include <string>

struct IListener {
    virtual ~IListener() = default;
    virtual void onNewBlock(const std::vector<std::string>& block) = 0;
};

#endif //BULKPROJECT_ILISTENER_H
