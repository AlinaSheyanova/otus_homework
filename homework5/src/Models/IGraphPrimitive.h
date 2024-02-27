//
// Created by Lina1 on 11.02.2024.
//

#pragma once

#include "Point.h"

class IGraphElement
{
protected:

    Point startPoint;
    Point endPoint;

public:

    virtual void draw() = 0;

    virtual bool contains(Point point) = 0;

};