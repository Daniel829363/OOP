#include <iostream>
#include <string>
#include <ctime>
#include "Header.h"

class Timer {
private:
    int seconds;

public:
    // Конструктор с указанием времени в секундах (целое число)
    Timer(int sec) : seconds(sec) {}

    ~Timer() {

    }
    // Функция для запуска таймера
    void run(int sec) {
        seconds = sec;
        while (seconds > 0) {
            std::cout << "Осталось времени: " << seconds << " секунд." << std::endl;
            std::cout << "Тик-так..." << std::endl;
            std::cout << std::endl;

            // Имитация ожидания 1 секунды
            delay(1000);

            seconds--;
        }

        std::cout << "Звонок! Время истекло." << std::endl;
    }

    void run(const std::string& time) {
        parseTimeString(time);
        while (seconds > 0) {
            std::cout << "Осталось времени: " << seconds << " секунд." << std::endl;
            std::cout << "Тик-так..." << std::endl;
            std::cout << std::endl;

            // Имитация ожидания 1 секунды
            delay(1000);

            seconds--;
        }

        std::cout << "Звонок! Время истекло." << std::endl;
    }
    void run(int minutes, int sec) {
        seconds = minutes * 60 + sec;
        while (seconds > 0) {
            std::cout << "Осталось времени: " << seconds << " секунд." << std::endl;
            std::cout << "Тик-так..." << std::endl;
            std::cout << std::endl;

            // Имитация ожидания 1 секунды
            delay(1000);

            seconds--;
        }

        std::cout << "Звонок! Время истекло." << std::endl;
    }
private:
    // Функция для разбора строки времени и установки соответствующего значения в секундах
    void parseTimeString(const std::string& time) {
        size_t found = time.find(':');
        if (found != std::string::npos) {
            int minutes = std::stoi(time.substr(0, found));
            int sec = std::stoi(time.substr(found + 1));
            seconds = minutes * 60 + sec;
        }
        else {
            seconds = std::stoi(time);
        }
    }

    // Функция для имитации ожидания в миллисекундах
    void delay(int milliseconds) {
        clock_t start_time = clock();
        while (clock() < start_time + milliseconds);
    }
};

int lab3z1() {
    int i;
    k:std::cout << "Введите номер задачи: ";
    std::cin >> i;
    if (i == 2) {
        lab3z2();goto k;
    }
    else if (i == 3) {
        lab3z3();goto k;
    }
    // Примеры использования класса Timer
    int n, m;
    std::string t;
    std::cout << "Введите время(1 число): ";
    std::cin >> n;
    Timer timer1(n);              
    /*Timer timer2("0:10");           
    Timer timer3(0, 15); */           

    timer1.run(n);

    std::cout << "Введите время (2 числа через пробел): ";
    std::cin >> m;
    std::cin >> n;
    
    timer1.run(m,n);

    std::cout << "Введите время (время через : ): ";
    std::cin >> t;

    timer1.run(t);

    return 0;
}
