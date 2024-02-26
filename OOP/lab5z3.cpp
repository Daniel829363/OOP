#include <iostream>
#include "Header.h"

class Rectangle {
private:
    double length;
    double width;

public:
    // ����������� � �����������
    Rectangle(double l, double w) : length(l), width(w) {}
    Rectangle(double k) : length(k), width(k) {}

    // ���������� ������ rect_area() ��� ��������������
    double rect_area(double l, double w)  {
        this->length = l;
        this->width = w;
        return l * w;
    }

    // ���������� ������ rect_area() ��� ��������
    double rect_area() const {
        return length * width;
    }
};

int lab5z3() {
    Rectangle rect1(4,6); // �������������
    Rectangle rect2(5);    // �������

    // ���������� ������� ��������������
    std::cout << "������� ��������������: " << rect1.rect_area(4,6) << std::endl;

    // ���������� ������� ��������
    std::cout << "������� ��������: " << rect2.rect_area() << std::endl;

    return 0;
}
