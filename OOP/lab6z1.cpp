#include <iostream>
#include <string>
#include "Header.h"

class Employee {
protected: // ���������� protected, ����� ���� ���� �������� � ������-�������
    std::string name;
    std::string position;
    double salary;

public:
    // ����������� �� ���������
    Employee() : name(""), position(""), salary(0) {}

    // ����������� � �����������
    Employee(const std::string& name, const std::string& position, double salary)
        : name(name), position(position), salary(salary) {}

    // ����������
    virtual ~Employee() {}

    double GetSalary() const {
        return salary;
    }
    // ������ �������� �� ���
    double calculateAnnualSalary() const {
        return salary * 12;
    }

    // ���������� ���������� � ��������� �� �������
    void display() const {
        std::cout << "���: " << name << std::endl;
        std::cout << "���������: " << position << std::endl;
        std::cout << "�������� �� �����: " << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // ����������� �� ���������
    Manager() : Employee(), annual_bonus(0), company_car(""), stock_options(0) {}

    // ����������� � �����������
    Manager(const std::string& name, const std::string& position, double salary,
        double annual_bonus, const std::string& company_car, int stock_options)
        : Employee(name, position, salary), annual_bonus(annual_bonus),
        company_car(company_car), stock_options(stock_options) {}

    // ����������
    ~Manager() override {}

    // ���������� ���������� � ��������� �� �������
    void display() const {
        std::cout << "���: " << name << std::endl;
        std::cout << "���������: " << position << std::endl;
        std::cout << "�������� �� �����: " << GetSalary() << std::endl;
        std::cout << "��������� �����: " << annual_bonus << std::endl;
        std::cout << "������ ��������: " << company_car << std::endl;
        std::cout << "������� �� �����: " << stock_options << std::endl;
    }
};
class Manager2 : private Manager {
private:
    double annual_bonus2;
    std::string company_car2;
    int stock_options2;

public:
    // ����������� �� ���������
    Manager2() : Manager(), annual_bonus2(0), company_car2(""), stock_options2(0) {}

    // ����������� � �����������
    Manager2(const std::string& name, const std::string& position, double salary,
        double annual_bonus, const std::string& company_car, int stock_options)
        : Manager(name, position, salary, annual_bonus, company_car, stock_options), annual_bonus2(annual_bonus),
        company_car2(company_car), stock_options2(stock_options) {}

    // ����������
    ~Manager2() override {}

    // ���������� ���������� � ��������� �� �������
    void display() const {
        std::cout << "���: " << name << std::endl;
        std::cout << "���������: " << position << std::endl;
        std::cout << "�������� �� �����: " << salary << std::endl;
        std::cout << "��������� �����: " << annual_bonus2 << std::endl;
        std::cout << "������ ��������: " << company_car2 << std::endl;
        std::cout << "������� �� �����: " << stock_options2 << std::endl;
    }
};

int lab6z1() {

    int i;
k:std::cout << "������� ����� ������: ";
    std::cin >> i;

    if (i == 1);
    else if (i == 2) {
        lab6z2(); goto k;
    }
    else if (i == 3) {
        lab6z3(); goto k;
    }
    else return 0;
    // ������������ ������ Employee
    Employee emp("������", "�������", 5000);
    emp.display();
    std::cout << "������� ��������: " << emp.calculateAnnualSalary() << std::endl;

    std::cout << std::endl;

    // ������������ ������ Manager
    Manager manager("������", "��������", 8000, 2000, "Audi", 100);
    manager.display();
    std::cout << "������� ��������: " << manager.calculateAnnualSalary() << std::endl;
    goto k;
    return 0;
}
