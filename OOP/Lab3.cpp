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
//    // ����������� ��� ������������� ������� � �������� (����� �����)
//    Timer(int initialSeconds) : seconds(initialSeconds) {}
//
//    // ����������� ��� ������������� ������� �� ������
//    Timer(const std::string& timeString) {
//        parseTimeString(timeString);
//    }
//
//    // ����������� ��� ������������� ������� � ������� � �������� (��� ����� �����)
//    Timer(int minutes, int seconds) : seconds(minutes * 60 + seconds) {}
//
//    // ������� ��� ������� �������
//    void run() {
//        while (seconds > 0) {
//            std::this_thread::sleep_for(std::chrono::seconds(1));
//            --seconds;
//        }
//        std::cout << "������! ������ �������� ������.\n";
//    }
//
//private:
//    // ������� ��� ������� ������ ������� � ��������� ���������������� ��������
//    void parseTimeString(const std::string& timeString) {
//        size_t pos = timeString.find(':');
//        if (pos != std::string::npos) {
//            // ������ ������� � ������� � ��������: "��:��"
//            int minutes = std::stoi(timeString.substr(0, pos));
//            int seconds = std::stoi(timeString.substr(pos + 1));
//            this->seconds = minutes * 60 + seconds;
//        }
//        else {
//            // ������ ������� � ��������
//            this->seconds = std::stoi(timeString);
//        }
//    }
//};
//
//int lab3() {
//    // ������� ������������� �������������
//    Timer timer1(5); // ������������� ������� � ��������
//    Timer timer2("0:10"); // ������������� ������� � ������� � ��������
//    Timer timer3(0, 15); // ������������� ������� � ������� � ��������
//
//    // ������ ��������
//    std::thread t1(&Timer::run, &timer1);
//    std::thread t2(&Timer::run, &timer2);
//    std::thread t3(&Timer::run, &timer3);
//
//    // �������� ���������� ���� �������
//    t1.join();
//    t2.join();
//    t3.join();
//
//    return 0;
//}
