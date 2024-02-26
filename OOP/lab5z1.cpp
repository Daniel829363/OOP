#include <iostream>
#include <limits>
#include "Header.h"

class Int {
private:
    int value;

public:
    Int(int val) : value(val) {}

    // �������� ���������
    Int operator+(const Int& other) const {
        if ((long double)value + other.value > std::numeric_limits<int>::max() ||
            (long double)value + other.value < std::numeric_limits<int>::min()) {
            throw std::overflow_error("�������������� ������������");
        }
        return Int(value + other.value);
    }

    Int operator-(const Int& other) const {
        if ((long double)value - other.value > std::numeric_limits<int>::max() ||
            (long double)value - other.value < std::numeric_limits<int>::min()) {
            throw std::overflow_error("�������������� ������������");
        }
        return Int(value - other.value);
    }

    Int operator*(const Int& other) const {
        if ((long double)value * other.value > std::numeric_limits<int>::max() ||
            (long double)value * other.value < std::numeric_limits<int>::min()) {
            throw std::overflow_error("�������������� ������������");
        }
        return Int(value * other.value);
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw std::runtime_error("������� �� ����");
        }
        return Int(value / other.value);
    }

    // ���������� ����� ����������
    Int& operator++() {
        if (value == std::numeric_limits<int>::max()) {
            throw std::overflow_error("�������������� ������������");
        }
        ++value;
        return *this;
    }

    // ����������� ����� ����������
    Int operator++(int) {
        if (value == std::numeric_limits<int>::max()) {
            throw std::overflow_error("�������������� ������������");
        }
        Int temp = *this;
        ++(*this);
        return temp;
    }

    // ����� ��������
    void display() const {
        std::cout << "��������: " << value << std::endl;
    }
};

int lab5z1() {
hh:
    int k;
    std::cout << "Number of zadanie: ";
    std::cin >> k;
    if (k == 0)return 0;
    else if (k == 2){lab5z2(); goto hh;}
    else if (k == 3){lab5z3(); goto hh;}
    
    int n = 2147483647,i=0;
g:
    try {
        Int a(n);//2147483647);
        Int b(1);
        a.display();
        b.display();
        // �������� ��������������� ������������ ��� �������� �������� � ����������
        Int c = a + b;
        c.display();
        ++c;
        c.display();

        // �������� ������� �� ����
        Int d(10);
        Int e(0);
        Int f = d / e;
        f.display(); // �� ����� ���������

    }
    catch (const std::overflow_error& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "������: " << e.what() << std::endl;
        i = 1;
    }
    n = 1;
    if(i!=1)goto g;
    goto hh;
    return 0;
}
