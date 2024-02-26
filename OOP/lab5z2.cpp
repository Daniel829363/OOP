#include <iostream>
#include "Header.h"

class fraction {
private:
    double chislo;

public:
    // Конструктор по умолчанию
    fraction() : chislo(0) {}

    // Конструктор с одним аргументом
    fraction(double val) : chislo(val) {}

    // Перегрузка оператора сложения
    fraction operator+(const fraction& other) const {
        return fraction(chislo + other.chislo);
    }

    // Перегрузка оператора вычитания
    fraction operator-(const fraction& other) const {
        return fraction(chislo - other.chislo);
    }

    // Перегрузка оператора умножения
    fraction operator*(const fraction& other) const {
        return fraction(chislo * other.chislo);
    }

    // Перегрузка оператора деления
    fraction operator/(const fraction& other) const {
        if (other.chislo == 0) {
            std::cerr << "Деление на ноль!" << std::endl;
            return fraction();
        }
        return fraction(chislo / other.chislo);
    }

    // Перегрузка унарной операции инкремента в постфиксной форме
    fraction operator++(int) {
        fraction temp(*this);
        chislo++;
        return temp;
    }

    // Перегрузка унарной операции инкремента в префиксной форме
    fraction& operator++() {
        ++chislo;
        return *this;
    }

    // Вывод значения
    void display() const {
        std::cout << "Значение: " << chislo << std::endl;
    }
};

int lab5z2() {
    fraction a(3.0); // Дробь 3.0
    fraction b(0.5); // Дробь 0.5

    // Примеры использования арифметических операторов
    fraction c = a + b; // Сложение дробей
    c.display(); // Ожидаем 3.5

    fraction d = a + 4; // Сложение дроби с числом
    d.display(); // Ожидаем 7.0

    fraction e = a * 4; // Умножение числа на дробь
    e.display(); // Ожидаем 12.0

    fraction f = b - 0.25; // Вычитание числа из дроби
    f.display(); // Ожидаем 0.25

    fraction g = a / b; // Деление дробей
    g.display(); // Ожидаем 6.0

    // Пример использования унарной операции инкремента
    fraction h = ++a; // Инкремент дроби в префиксной форме
    h.display(); // Ожидаем 4.0

    fraction i = b++; // Инкремент дроби в постфиксной форме
    i.display(); // Ожидаем 0.5

    return 0;
}
