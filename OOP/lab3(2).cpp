#include <iostream>
#include <string>
#include "Header.h"

class Nomenclature {
private:
    std::string itemName;
    double wholesalePrice;
    double retailMarkup;
    int stockQuantity;

public:
    // ����������� �� ���������
    Nomenclature() : itemName(""), wholesalePrice(0.0), retailMarkup(0.0), stockQuantity(0) {}

    // ����������� � �����������
    Nomenclature(const std::string& name, double wholesale, double markup, int quantity)
        : itemName(name), wholesalePrice(wholesale), retailMarkup(markup), stockQuantity(quantity) {}

    // ����������
    ~Nomenclature() {
        std::cout << "����� \"" << itemName << "\" ������." << std::endl;
    }

    // ������� ��� �������� ������� ������ ��� ������� ������
    double calculateNetIncome(int soldQuantity) const {
        double revenue = (wholesalePrice + retailMarkup) * soldQuantity;
        double expenses = wholesalePrice * soldQuantity;
        return revenue - expenses;
    }

    // ������� ��� ������ ������ � ������ �� �����
    void displayItemDetails() const {
        std::cout << "�������� ������: " << itemName << std::endl;
        std::cout << "������� ����: " << wholesalePrice << " ���." << std::endl;
        std::cout << "��������� �������: " << retailMarkup << " ���." << std::endl;
        std::cout << "���������� �� ������: " << stockQuantity << " ��." << std::endl;
    }
};

int lab3z2() {
    // ������ ������������� ������ Nomenclature
    Nomenclature item1("������", 50000.0, 100000.0, 10);

    // ����� ������ � ������
    item1.displayItemDetails();

    // ������� 5 ���� ������
    int soldQuantity = 5;
    double netIncome = item1.calculateNetIncome(soldQuantity);

    std::cout << "��� ������� " << soldQuantity << " ���� ������ ������ ����� ��������: " << netIncome << " ���." << std::endl;

    return 0;
}
