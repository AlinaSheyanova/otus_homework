#pragma once

#include <iostream>

#include "IGraphPrimitive.h"

/**
 * @class Rectangle
 * @brief A class representing a rectangle in a 2D Cartesian coordinate system.
 *
 * This class extends the IGraphElement interface and provides the implementation
 * for drawing and containing a point within the rectangle.
 *
 * @inherit IGraphElement
 */
class Rectangle : public IGraphElement {

public:
    /**
     * @brief Draws the rectangle.
     *
     * This function overrides the draw() function in the IGraphElement interface.
     * It prints a message indicating that the rectangle is being drawn.
     */
    void draw() override;

    /**
     * @brief Checks if a given point is contained within the rectangle.
     *
     * This function checks if the X and Y coordinates of the given point fall within the range defined by the startPoint and endPoint of the rectangle.
     *
     * @param point The point to be checked for containment.
     * @return True if the point is inside the rectangle, false otherwise.
     */
    bool contains(Point point) override;
};

