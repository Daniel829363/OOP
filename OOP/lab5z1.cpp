#include <iostream>
#include <limits>
#include "Header.h"

class Int {
private:
    int value;

public:
    Int(int val) : value(val) {}

    // Бинарные операторы
    Int operator+(const Int& other) const {
        if ((long double)value + other.value > std::numeric_limits<int>::max() ||
            (long double)value + other.value < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Арифметическое переполнение");
        }
        return Int(value + other.value);
    }

    Int operator-(const Int& other) const {
        if ((long double)value - other.value > std::numeric_limits<int>::max() ||
            (long double)value - other.value < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Арифметическое переполнение");
        }
        return Int(value - other.value);
    }

    Int operator*(const Int& other) const {
        if ((long double)value * other.value > std::numeric_limits<int>::max() ||
            (long double)value * other.value < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Арифметическое переполнение");
        }
        return Int(value * other.value);
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Деление на ноль");
        }
        return Int(value / other.value);
    }

    // Префиксная форма инкремента
    Int& operator++() {
        if (value == std::numeric_limits<int>::max()) {
            throw std::overflow_error("Арифметическое переполнение");
        }
        ++value;
        return *this;
    }

    // Постфиксная форма инкремента
    Int operator++(int) {
        if (value == std::numeric_limits<int>::max()) {
            throw std::overflow_error("Арифметическое переполнение");
        }
        Int temp = *this;
        ++(*this);
        return temp;
    }

    // Вывод значения
    void display() const {
        std::cout << "Значение: " << value << std::endl;
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
        // Проверка арифметического переполнения для операций сложения и инкремента
        Int c = a + b;
        c.display();
        ++c;
        c.display();

        // Проверка деления на ноль
        Int d(10);
        Int e(0);
        Int f = d / e;
        f.display(); // Не будет выполнено

    }
    catch (const std::overflow_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        i = 1;
    }
    n = 1;
    if(i!=1)goto g;
    goto hh;
    return 0;
}
