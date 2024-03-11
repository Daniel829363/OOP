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
        // Предполагаем курс доллара к рублю равным 75
        return amount * 75;
    }

    void displayAmount(double amount) const override {
        std::cout << "$" << amount;
    }
};

class Euro : public Currency {
public:
    double toRubles(double amount) const override {
        // Предполагаем курс евро к рублю равным 90
        return amount * 90;
    }

    void displayAmount(double amount) const override {
        std::cout << "€" << amount;
    }
};

int lab7z3() {
    Dollar dollar;
    Euro euro;

    double amountDollars = 100;
    double amountEuros = 80;

    std::cout << "Сумма в долларах: ";
    dollar.displayAmount(amountDollars);
    std::cout << " равна " << dollar.toRubles(amountDollars) << " рублей." << std::endl;

    std::cout << "Сумма в евро: ";
    euro.displayAmount(amountEuros);
    std::cout << " равна " << euro.toRubles(amountEuros) << " рублей." << std::endl;

    return 0;
}
