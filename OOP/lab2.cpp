#include <iostream>
#include <vector>
#include <algorithm>
#include "Header.h"
#include <Windows.h>

class Aeroflot {
public:
    int flightNumber;
    std::string departureCity;
    std::string destinationCity;
    std::string arrivalTime;
    std::string departureTime;
    int registrationSection;

    Aeroflot(int num, const std::string& dep, const std::string& dest, const std::string& arr, const std::string& depTime, int regSec)
        : flightNumber(num), departureCity(dep), destinationCity(dest), arrivalTime(arr), departureTime(depTime), registrationSection(regSec) {}
};

// Функция для вывода значений полей объектов класса в виде таблицы рейсов
void printFlights(const std::vector<Aeroflot>& flights) {
    if (flights.empty()) {
        std::cout << "Нет доступных рейсов." << std::endl;
        return;
    }

    // Вывод заголовка таблицы
    std::cout << "------------------------------------------------------------------------\n";
    std::cout << "| № рейса | Пункт отправления | Пункт назначения | Время прибытия | Время отправления | Секция регистрации |\n";
    std::cout << "------------------------------------------------------------------------\n";

    // Вывод значений полей объектов в виде таблицы
    for (const auto& flight : flights) {
        std::cout << "| " << flight.flightNumber << "\t | " << flight.departureCity << "\t\t | " << flight.destinationCity << "\t\t | "
            << flight.arrivalTime << "\t | " << flight.departureTime << "\t\t | " << flight.registrationSection << "\t\t\t |\n";
    }

    std::cout << "------------------------------------------------------------------------\n";
}

int lab2() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);

    int n;
    hh:
    std::cout << "Введите номер задания: ";
    std::cin >> n;

    if (n == 1);
    else if (n == 2) {
        lab2z2();
        goto hh;
    }
    else if (n == 2) {
        lab2z2();
        goto hh;
    }
    else if (n == 3) {
        lab2z3();
        goto hh;
    }
    else return 0;

    std::vector<Aeroflot> flights;  // Вектор для хранения объектов класса Aeroflot

    // Ввод с клавиатуры значений полей объектов
    int num, regSec;
    std::string dep, dest, arr, depTime;
    char continueInput;

    do {
        std::cout << "Введите номер рейса: ";
        std::cin >> num;
        std::cout << "Введите пункт отправления: ";
        std::cin >> dep;
        std::cout << "Введите пункт назначения: ";
        std::cin >> dest;
        std::cout << "Введите время прибытия: ";
        std::cin >> arr;
        std::cout << "Введите время отправления: ";
        std::cin >> depTime;
        std::cout << "Введите номер секции для регистрации: ";
        std::cin >> regSec;

        flights.emplace_back(num, dep, dest, arr, depTime, regSec);

        std::cout << "Хотите добавить еще рейс? (y/n): ";
        std::cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');

    // Сортировка записей в таблице в алфавитном порядке по названию пунктов назначения
    std::sort(flights.begin(), flights.end(), [](const Aeroflot& a, const Aeroflot& b) {
        return a.destinationCity < b.destinationCity;
        });

    // Вывод на консоль значений полей объектов класса в виде таблицы рейсов
    printFlights(flights);

    return 0;
}
