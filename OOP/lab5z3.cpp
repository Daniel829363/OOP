#include <iostream>
#include "Header.h"

class Rectangle {
private:
    double length;
    double width;

public:
    // Конструктор с параметрами
    Rectangle(double l, double w) : length(l), width(w) {}
    Rectangle(double k) : length(k), width(k) {}

    // Перегрузка метода rect_area() для прямоугольника
    double rect_area(double l, double w)  {
        this->length = l;
        this->width = w;
        return l * w;
    }

    // Перегрузка метода rect_area() для квадрата
    double rect_area() const {
        return length * width;
    }
};

int lab5z3() {
    Rectangle rect1(4,6); // Прямоугольник
    Rectangle rect2(5);    // Квадрат

    // Вычисление площади прямоугольника
    std::cout << "Площадь прямоугольника: " << rect1.rect_area(4,6) << std::endl;

    // Вычисление площади квадрата
    std::cout << "Площадь квадрата: " << rect2.rect_area() << std::endl;

    return 0;
}
