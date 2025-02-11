#include <iostream>
#include <float.h>
#include <vector>

struct Point {
    double x;
    double y;

    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double x, double y) 
    {
        this->x = x;
        this->y = y;
    }

    // Print points coordinates
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

struct Rectangle
{
    double xMin = -1 * DBL_MAX;
    double yMin = -1 * DBL_MAX;
    double xMax = DBL_MAX;
    double yMax = DBL_MAX;

    // Set rectangle vertices
    void SetMinMaxXY()
    {
        std::cout << "Enter xMin yMin xMax yMax: ";
        std::cin >> xMin >> yMin >> xMax >> yMax;
    }

    // Check if point is in rectangle
    bool isPointInRectangle(Point& point) {
        return (point.x >= xMin && point.x <= xMax && point.y >= yMin && point.y <= yMax);
    }
};

int main() {
    std::vector<Point> points;
    Rectangle rectangle;
    int n;

    std::cout << "Enter count of points: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error: count of points must be positive!" << std::endl;
        return 1;
    }

    // Print points coordinates
    std::cout << "Enter point coordinates (x y):" << std::endl;
    for (int i = 0; i < n; i++) {
        double x, y;
        std::cout << "Point " << i + 1 << ": ";
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }

    rectangle.SetMinMaxXY();

    // Search and print points in rectangle
    std::cout << "Points in rectangle:" << std::endl;
    bool found = false;
    
    for (Point& point : points) {
        if (rectangle.isPointInRectangle(point)) {
            point.print();
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "There is no points in rectangle" << std::endl;
    }

    return 0;
}