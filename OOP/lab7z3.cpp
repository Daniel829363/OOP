#include <iostream>

class Currency {
public:
    virtual double toRubles(double amount) const = 0;
    virtual void displayAmount(double amount) const = 0;
    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    double toRubles(double amount) const override {
        // ������������ ���� ������� � ����� ������ 75
        return amount * 75;
    }

    void displayAmount(double amount) const override {
        std::cout << "$" << amount;
    }
};

class Euro : public Currency {
public:
    double toRubles(double amount) const override {
        // ������������ ���� ���� � ����� ������ 90
        return amount * 90;
    }

    void displayAmount(double amount) const override {
        std::cout << "�" << amount;
    }
};

int lab7z3() {
    Dollar dollar;
    Euro euro;

    double amountDollars = 100;
    double amountEuros = 80;

    std::cout << "����� � ��������: ";
    dollar.displayAmount(amountDollars);
    std::cout << " ����� " << dollar.toRubles(amountDollars) << " ������." << std::endl;

    std::cout << "����� � ����: ";
    euro.displayAmount(amountEuros);
    std::cout << " ����� " << euro.toRubles(amountEuros) << " ������." << std::endl;

    return 0;
}
