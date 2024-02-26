#include <iostream>
#include "Header.h"

class fraction {
private:
    double chislo;

public:
    // ����������� �� ���������
    fraction() : chislo(0) {}

    // ����������� � ����� ����������
    fraction(double val) : chislo(val) {}

    // ���������� ��������� ��������
    fraction operator+(const fraction& other) const {
        return fraction(chislo + other.chislo);
    }

    // ���������� ��������� ���������
    fraction operator-(const fraction& other) const {
        return fraction(chislo - other.chislo);
    }

    // ���������� ��������� ���������
    fraction operator*(const fraction& other) const {
        return fraction(chislo * other.chislo);
    }

    // ���������� ��������� �������
    fraction operator/(const fraction& other) const {
        if (other.chislo == 0) {
            std::cerr << "������� �� ����!" << std::endl;
            return fraction();
        }
        return fraction(chislo / other.chislo);
    }

    // ���������� ������� �������� ���������� � ����������� �����
    fraction operator++(int) {
        fraction temp(*this);
        chislo++;
        return temp;
    }

    // ���������� ������� �������� ���������� � ���������� �����
    fraction& operator++() {
        ++chislo;
        return *this;
    }

    // ����� ��������
    void display() const {
        std::cout << "��������: " << chislo << std::endl;
    }
};

int lab5z2() {
    fraction a(3.0); // ����� 3.0
    fraction b(0.5); // ����� 0.5

    // ������� ������������� �������������� ����������
    fraction c = a + b; // �������� ������
    c.display(); // ������� 3.5

    fraction d = a + 4; // �������� ����� � ������
    d.display(); // ������� 7.0

    fraction e = a * 4; // ��������� ����� �� �����
    e.display(); // ������� 12.0

    fraction f = b - 0.25; // ��������� ����� �� �����
    f.display(); // ������� 0.25

    fraction g = a / b; // ������� ������
    g.display(); // ������� 6.0

    // ������ ������������� ������� �������� ����������
    fraction h = ++a; // ��������� ����� � ���������� �����
    h.display(); // ������� 4.0

    fraction i = b++; // ��������� ����� � ����������� �����
    i.display(); // ������� 0.5

    return 0;
}
