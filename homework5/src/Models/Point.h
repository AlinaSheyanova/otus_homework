//
// Created by Lina1 on 26.03.2024.
//

#ifndef HELLOWORLD_POINT_H
#define HELLOWORLD_POINT_H

class Point
{
public:
    double X;
    double Y;

public:
    Point() {};

    Point(double x, double y) : X(x), Y(y) {}

    Point(const Point &other) : X(other.X), Y(other.Y) {}

    Point &operator=(const Point &other) {
        X = other.X;
        Y = other.Y;
        return *this;
    }

};

#endif //HELLOWORLD_POINT_H
