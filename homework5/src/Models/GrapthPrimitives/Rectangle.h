//
// Created by Lina1 on 26.03.2024.
//

#ifndef HELLOWORLD_RECTANGLE_H
#define HELLOWORLD_RECTANGLE_H

#include <iostream>

#include "../IGraphPrimitive.h"

class Rectangle : public IGraphElement {

public:
    void draw() override {
        std::cout << "Drawing Rectangle.\n";
    }

    bool contains(Point point) override
    {
        return (point.X >= startPoint.X && point.X <= endPoint.X
        && point.Y >= startPoint.Y && point.Y <= endPoint.Y );
    }
};

#endif //HELLOWORLD_RECTANGLE_H
