#include <iostream>
#include <string>
#include "Header.h"

class Employee {
private: // Закрываем доступ к полям базового класса
    std::string name;
    std::string position;
    double salary;

public:
    // Конструктор с аргументами
    Employee(const std::string& _name, const std::string& _position, double _salary)
        : name(_name), position(_position), salary(_salary) {}

    // Деструктор
    virtual ~Employee() {}

    // Расчет зарплаты за год
    double calculateAnnualSalary() {
        return salary * 12;
    }

    double getS() const {
        return salary;
    }
    // Размещение информации о работнике на консоли
    void display() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Должность: " << position << std::endl;
        std::cout << "Зарплата за месяц: " << salary << std::endl;
    }
};

class Manager : private Employee { // Закрыт доступ к членам базового класса
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // Конструктор с аргументами
    Manager(const std::string& _name, const std::string& _position, double _salary,
        double _annual_bonus, const std::string& _company_car, int _stock_options)
        : Employee(_name, _position, _salary), annual_bonus(_annual_bonus),
        company_car(_company_car), stock_options(_stock_options) {}

    double calculateAnnualSalary() {
        double g = this->getS();
        return g * 12;
    }
    // Размещение информации о менеджере на консоли
    void display() const {
        Employee::display(); // Вызов метода display из базового класса
        std::cout << "Ежегодный бонус: " << annual_bonus << std::endl;
        std::cout << "Машина компании: " << company_car << std::endl;
        std::cout << "Опционы на акции: " << stock_options << std::endl;
    }
};

int lab6z3() {
    // Тестирование класса Employee
    Employee emp("Иванов", "Инженер", 5000);
    emp.display();
    std::cout << "Годовая зарплата: " << emp.calculateAnnualSalary() << std::endl;

    std::cout << std::endl;

    // Тестирование класса Manager
    Manager manager("Петров", "Менеджер", 8000, 2000, "Audi", 100);
    manager.display();
    //manager.getS();
    std::cout << "Годовая зарплата: " << manager.calculateAnnualSalary() << std::endl;

    return 0;
}
