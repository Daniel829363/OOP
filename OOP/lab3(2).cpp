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
    // Конструктор по умолчанию
    Nomenclature() : itemName(""), wholesalePrice(0.0), retailMarkup(0.0), stockQuantity(0) {}

    // Конструктор с параметрами
    Nomenclature(const std::string& name, double wholesale, double markup, int quantity)
        : itemName(name), wholesalePrice(wholesale), retailMarkup(markup), stockQuantity(quantity) {}

    // Деструктор
    ~Nomenclature() {
        std::cout << "Товар \"" << itemName << "\" удален." << std::endl;
    }

    // Функция для подсчета чистого дохода при продаже товара
    double calculateNetIncome(int soldQuantity) const {
        double revenue = (wholesalePrice + retailMarkup) * soldQuantity;
        double expenses = wholesalePrice * soldQuantity;
        return revenue - expenses;
    }

    // Функция для вывода данных о товаре на экран
    void displayItemDetails() const {
        std::cout << "Название товара: " << itemName << std::endl;
        std::cout << "Оптовая цена: " << wholesalePrice << " руб." << std::endl;
        std::cout << "Розничная наценка: " << retailMarkup << " руб." << std::endl;
        std::cout << "Количество на складе: " << stockQuantity << " шт." << std::endl;
    }
};

int lab3z2() {
    // Пример использования класса Nomenclature
    Nomenclature item1("Лаптоп", 50000.0, 100000.0, 10);

    // Вывод данных о товаре
    item1.displayItemDetails();

    // Продажа 5 штук товара
    int soldQuantity = 5;
    double netIncome = item1.calculateNetIncome(soldQuantity);

    std::cout << "При продаже " << soldQuantity << " штук товара чистый доход составит: " << netIncome << " руб." << std::endl;

    return 0;
}
