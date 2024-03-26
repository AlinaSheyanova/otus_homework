#include "Line.h"

void Line::draw() {
    std::cout << "Drawing Line.\n";
}

bool Line::contains(Point point) {
    return std::abs((point.Y - startPoint.Y)/(endPoint.Y - startPoint.Y)
                    - (point.X - startPoint.X)/(endPoint.X - startPoint.X)) < std::numeric_limits<double>::epsilon();

}
