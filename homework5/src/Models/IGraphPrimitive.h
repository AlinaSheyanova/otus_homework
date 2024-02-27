#pragma once

#include "Point.h"

/**
 * @class IGraphElement
 * @brief The abstract base class for graph elements.
 *
 * This class represents a graph element, such as a line or a shape, that can be drawn on a graph.
 * It provides common functionality for drawing and testing containment.
 */
class IGraphElement
{
protected:

    Point startPoint;
    Point endPoint;

public:

    /**
     * @brief Virtual function to draw the graph element.
     *
     * This function is a pure virtual function that must be implemented by the derived classes.
     * It is used to draw the graph element on the graph.
     */
    virtual void draw() = 0;

    /**
     * @brief Checks if a given point is contained within the graph element.
     * @param point The point to check.
     * @return True if the point is contained within the graph element, false otherwise.
     *
     * This function is a pure virtual function that must be implemented by the derived classes.
     * It checks if the given point is contained within the graph element, based on its shape and coordinates.
     */
    virtual bool contains(Point point) = 0;

};