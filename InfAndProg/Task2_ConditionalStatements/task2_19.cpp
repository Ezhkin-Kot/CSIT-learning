#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-6;

// Точка с координатами 'x' и 'y'
struct Point {
    double x, y;
};

// Вычисление расстояния между точками
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Проверка равенства двух чисел типа double
bool isEqual(double a, double b) {
    return abs(a - b) < EPS;
}

// Проверка параллельности двух векторов (AB и CD)
bool areParallel(Point A, Point B, Point C, Point D) {
    return isEqual((B.x - A.x) * (D.y - C.y), (B.y - A.y) * (D.x - C.x));
}

// Проверка, является ли четырёхугольник параллелограммом
bool isParallelogram(Point A, Point B, Point C, Point D) {
    return areParallel(A, B, C, D) && areParallel(A, D, B, C);
}

// Вычисление площади параллелограмма
double areaParallelogram(Point A, Point B, Point C) {
    return abs((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x));
}

// Проверка, является ли параллелограмм прямоугольником (если диагонали равны)
bool isRectangle(Point A, Point B, Point C, Point D) {
    double diag1 = distance(A, C);
    double diag2 = distance(B, D);
    return isEqual(diag1, diag2);
}

// Проверка, является ли параллелограмм ромбом (если все стороны равны)
bool isRhombus(Point A, Point B, Point C, Point D) {
    double side1 = distance(A, B);
    double side2 = distance(B, C);
    return isEqual(side1, side2);
}

// Проверка, является ли параллелограмм квадратом
bool isSquare(Point A, Point B, Point C, Point D) {
    return isRectangle(A, B, C, D) && isRhombus(A, B, C, D);
}

int main() {
    Point A, B, C, D;

    // Ввод координат вершин четырёхугольника
    cout << "Введите координаты вершин четырёхугольника A(xa, ya), B(xb, yb), C(xc, yc), D(xd, yd):\n";
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    // Проверка, является ли четырёхугольник параллелограммом
    if (isParallelogram(A, B, C, D)) {
        double area = areaParallelogram(A, B, C);
        double perimeter = 2 * (distance(A, B) + distance(B, C));

        if (isSquare(A, B, C, D)) {
            cout << "Квадрат" << endl;
            cout << "Площадь: " << area << "\nПериметр: " << perimeter << endl;
        }
        else if (isRectangle(A, B, C, D)) {
            cout << "Прямоугольник" << endl;
            cout << "Площадь: " << area << "\nПериметр: " << perimeter << endl;
        }
        else if (isRhombus(A, B, C, D)) {
            cout << "Ромб" << endl;
            cout << "Площадь: " << area << "\nПериметр: " << perimeter << endl;
        }
        else {
            cout << "Параллелограмм" << endl;
            cout << "Площадь: " << area << "\nПериметр: " << perimeter << endl;
        }
    }
    else {
        cout << "Не параллелограмм" << endl;
    }

    return 0;
}