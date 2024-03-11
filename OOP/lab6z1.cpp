#include <iostream>
#include <string>
#include "Header.h"

class Employee {
protected: // Используем protected, чтобы поля были доступны в классе-потомке
    std::string name;
    std::string position;
    double salary;

public:
    // Конструктор по умолчанию
    Employee() : name(""), position(""), salary(0) {}

    // Конструктор с аргументами
    Employee(const std::string& name, const std::string& position, double salary)
        : name(name), position(position), salary(salary) {}

    // Деструктор
    virtual ~Employee() {}

    double GetSalary() const {
        return salary;
    }
    // Расчет зарплаты за год
    double calculateAnnualSalary() const {
        return salary * 12;
    }

    // Размещение информации о работнике на консоли
    void display() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Должность: " << position << std::endl;
        std::cout << "Зарплата за месяц: " << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // Конструктор по умолчанию
    Manager() : Employee(), annual_bonus(0), company_car(""), stock_options(0) {}

    // Конструктор с аргументами
    Manager(const std::string& name, const std::string& position, double salary,
        double annual_bonus, const std::string& company_car, int stock_options)
        : Employee(name, position, salary), annual_bonus(annual_bonus),
        company_car(company_car), stock_options(stock_options) {}

    // Деструктор
    ~Manager() override {}

    // Размещение информации о менеджере на консоли
    void display() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Должность: " << position << std::endl;
        std::cout << "Зарплата за месяц: " << GetSalary() << std::endl;
        std::cout << "Ежегодный бонус: " << annual_bonus << std::endl;
        std::cout << "Машина компании: " << company_car << std::endl;
        std::cout << "Опционы на акции: " << stock_options << std::endl;
    }
};
class Manager2 : private Manager {
private:
    double annual_bonus2;
    std::string company_car2;
    int stock_options2;

public:
    // Конструктор по умолчанию
    Manager2() : Manager(), annual_bonus2(0), company_car2(""), stock_options2(0) {}

    // Конструктор с аргументами
    Manager2(const std::string& name, const std::string& position, double salary,
        double annual_bonus, const std::string& company_car, int stock_options)
        : Manager(name, position, salary, annual_bonus, company_car, stock_options), annual_bonus2(annual_bonus),
        company_car2(company_car), stock_options2(stock_options) {}

    // Деструктор
    ~Manager2() override {}

    // Размещение информации о менеджере на консоли
    void display() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Должность: " << position << std::endl;
        std::cout << "Зарплата за месяц: " << salary << std::endl;
        std::cout << "Ежегодный бонус: " << annual_bonus2 << std::endl;
        std::cout << "Машина компании: " << company_car2 << std::endl;
        std::cout << "Опционы на акции: " << stock_options2 << std::endl;
    }
};

int lab6z1() {

    int i;
k:std::cout << "Введите номер задачи: ";
    std::cin >> i;

    if (i == 1);
    else if (i == 2) {
        lab6z2(); goto k;
    }
    else if (i == 3) {
        lab6z3(); goto k;
    }
    else return 0;
    // Тестирование класса Employee
    Employee emp("Иванов", "Инженер", 5000);
    emp.display();
    std::cout << "Годовая зарплата: " << emp.calculateAnnualSalary() << std::endl;

    std::cout << std::endl;

    // Тестирование класса Manager
    Manager manager("Петров", "Менеджер", 8000, 2000, "Audi", 100);
    manager.display();
    std::cout << "Годовая зарплата: " << manager.calculateAnnualSalary() << std::endl;
    goto k;
    return 0;
}
