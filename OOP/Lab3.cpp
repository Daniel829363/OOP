//#include <iostream>
//#include <string>
//#include <chrono>
//#include <thread>
//#include "Header.h"
//
//class Timer {
//private:
//    int seconds;
//
//public:
//    // Конструктор для инициализации времени в секундах (целое число)
//    Timer(int initialSeconds) : seconds(initialSeconds) {}
//
//    // Конструктор для инициализации времени из строки
//    Timer(const std::string& timeString) {
//        parseTimeString(timeString);
//    }
//
//    // Конструктор для инициализации времени в минутах и секундах (два целых числа)
//    Timer(int minutes, int seconds) : seconds(minutes * 60 + seconds) {}
//
//    // Функция для запуска таймера
//    void run() {
//        while (seconds > 0) {
//            std::this_thread::sleep_for(std::chrono::seconds(1));
//            --seconds;
//        }
//        std::cout << "Звонок! Таймер закончил отсчет.\n";
//    }
//
//private:
//    // Функция для разбора строки времени и установки соответствующего значения
//    void parseTimeString(const std::string& timeString) {
//        size_t pos = timeString.find(':');
//        if (pos != std::string::npos) {
//            // Формат времени в минутах и секундах: "мм:сс"
//            int minutes = std::stoi(timeString.substr(0, pos));
//            int seconds = std::stoi(timeString.substr(pos + 1));
//            this->seconds = minutes * 60 + seconds;
//        }
//        else {
//            // Формат времени в секундах
//            this->seconds = std::stoi(timeString);
//        }
//    }
//};
//
//int lab3() {
//    // Примеры использования конструкторов
//    Timer timer1(5); // Инициализация времени в секундах
//    Timer timer2("0:10"); // Инициализация времени в минутах и секундах
//    Timer timer3(0, 15); // Инициализация времени в минутах и секундах
//
//    // Запуск таймеров
//    std::thread t1(&Timer::run, &timer1);
//    std::thread t2(&Timer::run, &timer2);
//    std::thread t3(&Timer::run, &timer3);
//
//    // Ожидание завершения всех потоков
//    t1.join();
//    t2.join();
//    t3.join();
//
//    return 0;
//}
