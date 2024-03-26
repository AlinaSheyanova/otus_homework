#pragma once
#include <iostream>
#include <cmath>

#include "IGraphPrimitive.h"

/**
 * @class Line
 * @brief Represents a line element in a graph.
 *
 * This class inherits from IGraphElement and provides
 * functionality to draw and check if a point is contained
 * within a line.
 */
class Line : public IGraphElement {

public:
    /**
     * @brief Draws the Line.
     *
     * This function is used to draw the Line. It prints "Drawing Line." to the console.
     * This function overrides the draw() function from the IGraphElement interface.
     */
    void draw() override {
        std::cout << "Drawing Line.\n";
    }

    /**
     * @brief Check if a given point is contained within the line segment defined by the start and end points.
     *
     * This function checks if the given point is on the line segment between the start and end points.
     *
     * @param point The point to be checked.
     * @return True if the point is contained within the line segment, false otherwise.
     */
    bool contains(Point point) override
    {
        return std::abs((point.Y - startPoint.Y)/(endPoint.Y - startPoint.Y)
        - (point.X - startPoint.X)/(endPoint.X - startPoint.X)) < std::numeric_limits<double>::epsilon();

    }
};

