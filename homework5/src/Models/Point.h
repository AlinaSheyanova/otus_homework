#pragma once

/**
 * @class Point
 * @brief Class representing a point in 2D space
 */
class Point
{
public:
    double X;
    double Y;

public:

    /**
     * @brief Constructs a Point object by default
     */
    Point() {};

    /**
     * @brief Constructs a Point object with the specified X and Y coordinates.
     *
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     */
    Point(double x, double y) : X(x), Y(y) {}

    /**
     * @brief Copy constructor for the Point class.
     *
     * This constructor creates a new Point object by copying the values of another Point object.
     *
     * @param other The Point object to be copied.
     */
    Point(const Point &other) : X(other.X), Y(other.Y) {}

    /**
     * @brief Overloads the assignment operator for the Point class
     *
     * This function assigns the values of another Point object to the current object.
     *
     * @param other The Point object to be assigned
     * @return Reference to the current Point object after assignment
     */
    Point &operator=(const Point &other) {
        X = other.X;
        Y = other.Y;
        return *this;
    }

};

