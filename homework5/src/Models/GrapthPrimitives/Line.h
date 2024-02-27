//
// Created by Lina1 on 26.03.2024.
//

#ifndef HELLOWORLD_LINE_H
#define HELLOWORLD_LINE_H

#include <iostream>
#include <cmath>

#include "../IGraphPrimitive.h"

class Line : public IGraphElement {

public:
    void draw() override {
        std::cout << "Drawing Line.\n";
    }

    bool contains(Point point) override
    {
        return std::abs((point.Y - startPoint.Y)/(endPoint.Y - startPoint.Y)
        - (point.X - startPoint.X)/(endPoint.X - startPoint.X)) < std::numeric_limits<double>::epsilon();

    }
};


#endif //HELLOWORLD_LINE_H
