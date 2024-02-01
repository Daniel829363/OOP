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

// ������� ��� ������ �������� ����� �������� ������ � ���� ������� ������
void printFlights(const std::vector<Aeroflot>& flights) {
    if (flights.empty()) {
        std::cout << "��� ��������� ������." << std::endl;
        return;
    }

    // ����� ��������� �������
    std::cout << "------------------------------------------------------------------------\n";
    std::cout << "| � ����� | ����� ����������� | ����� ���������� | ����� �������� | ����� ����������� | ������ ����������� |\n";
    std::cout << "------------------------------------------------------------------------\n";

    // ����� �������� ����� �������� � ���� �������
    for (const auto& flight : flights) {
        std::cout << "| " << flight.flightNumber << "\t | " << flight.departureCity << "\t\t | " << flight.destinationCity << "\t\t | "
            << flight.arrivalTime << "\t | " << flight.departureTime << "\t\t | " << flight.registrationSection << "\t\t\t |\n";
    }

    std::cout << "------------------------------------------------------------------------\n";
}

int lab2() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // ���� � ������� � ��������� 1251
    SetConsoleOutputCP(1251);

    int n;
    hh:
    std::cout << "������� ����� �������: ";
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

    std::vector<Aeroflot> flights;  // ������ ��� �������� �������� ������ Aeroflot

    // ���� � ���������� �������� ����� ��������
    int num, regSec;
    std::string dep, dest, arr, depTime;
    char continueInput;

    do {
        std::cout << "������� ����� �����: ";
        std::cin >> num;
        std::cout << "������� ����� �����������: ";
        std::cin >> dep;
        std::cout << "������� ����� ����������: ";
        std::cin >> dest;
        std::cout << "������� ����� ��������: ";
        std::cin >> arr;
        std::cout << "������� ����� �����������: ";
        std::cin >> depTime;
        std::cout << "������� ����� ������ ��� �����������: ";
        std::cin >> regSec;

        flights.emplace_back(num, dep, dest, arr, depTime, regSec);

        std::cout << "������ �������� ��� ����? (y/n): ";
        std::cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');

    // ���������� ������� � ������� � ���������� ������� �� �������� ������� ����������
    std::sort(flights.begin(), flights.end(), [](const Aeroflot& a, const Aeroflot& b) {
        return a.destinationCity < b.destinationCity;
        });

    // ����� �� ������� �������� ����� �������� ������ � ���� ������� ������
    printFlights(flights);

    return 0;
}
