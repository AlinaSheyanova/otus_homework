#include "Rectangle.h"

void Rectangle::draw() {
    std::cout << "Drawing Rectangle.\n";
}

bool Rectangle::contains(Point point) {
    return (point.X >= startPoint.X && point.X <= endPoint.X
            && point.Y >= startPoint.Y && point.Y <= endPoint.Y );
}
