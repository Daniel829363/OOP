#include <iostream>

class Figure {
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
protected:
    double width;
    double height;

public:
    Rectangle(double _width, double _height) : width(_width), height(_height) {}

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Circle : public Figure {
protected:
    double radius;

public:
    Circle(double _radius) : radius(_radius) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Trapezium : public Figure {
protected:
    double a; // Длина основания a
    double b; // Длина основания b
    double height; // Высота трапеции

public:
    Trapezium(double _a, double _b, double _height) : a(_a), b(_b), height(_height) {}

    double calculateArea() const override {
        return (a + b) * height / 2.0;
    }

    double calculatePerimeter() const override {
        // Для расчета периметра требуется знать боковые стороны трапеции, что не определено в условии
        // Предположим, что трапеция равнобокая, тогда боковые стороны равны sqrt((b - a)^2 + h^2)
        double side = std::sqrt((b - a) * (b - a) + height * height);
        return a + b + 2 * side;
    }
};

int lab7z2() {
    Rectangle rect(5, 3);
    Circle circle(4);
    Trapezium trapezium(2, 5, 4);

    std::cout << "Прямоугольник: Площадь = " << rect.calculateArea() << ", Периметр = " << rect.calculatePerimeter() << std::endl;
    std::cout << "Круг: Площадь = " << circle.calculateArea() << ", Длина окружности = " << circle.calculatePerimeter() << std::endl;
    std::cout << "Трапеция: Площадь = " << trapezium.calculateArea() << ", Периметр = " << trapezium.calculatePerimeter() << std::endl;

    return 0;
}
