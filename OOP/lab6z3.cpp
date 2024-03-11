#include <iostream>
#include <string>
#include "Header.h"

class Employee {
private: // ��������� ������ � ����� �������� ������
    std::string name;
    std::string position;
    double salary;

public:
    // ����������� � �����������
    Employee(const std::string& _name, const std::string& _position, double _salary)
        : name(_name), position(_position), salary(_salary) {}

    // ����������
    virtual ~Employee() {}

    // ������ �������� �� ���
    double calculateAnnualSalary() {
        return salary * 12;
    }

    double getS() const {
        return salary;
    }
    // ���������� ���������� � ��������� �� �������
    void display() const {
        std::cout << "���: " << name << std::endl;
        std::cout << "���������: " << position << std::endl;
        std::cout << "�������� �� �����: " << salary << std::endl;
    }
};

class Manager : private Employee { // ������ ������ � ������ �������� ������
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // ����������� � �����������
    Manager(const std::string& _name, const std::string& _position, double _salary,
        double _annual_bonus, const std::string& _company_car, int _stock_options)
        : Employee(_name, _position, _salary), annual_bonus(_annual_bonus),
        company_car(_company_car), stock_options(_stock_options) {}

    double calculateAnnualSalary() {
        double g = this->getS();
        return g * 12;
    }
    // ���������� ���������� � ��������� �� �������
    void display() const {
        Employee::display(); // ����� ������ display �� �������� ������
        std::cout << "��������� �����: " << annual_bonus << std::endl;
        std::cout << "������ ��������: " << company_car << std::endl;
        std::cout << "������� �� �����: " << stock_options << std::endl;
    }
};

int lab6z3() {
    // ������������ ������ Employee
    Employee emp("������", "�������", 5000);
    emp.display();
    std::cout << "������� ��������: " << emp.calculateAnnualSalary() << std::endl;

    std::cout << std::endl;

    // ������������ ������ Manager
    Manager manager("������", "��������", 8000, 2000, "Audi", 100);
    manager.display();
    //manager.getS();
    std::cout << "������� ��������: " << manager.calculateAnnualSalary() << std::endl;

    return 0;
}
