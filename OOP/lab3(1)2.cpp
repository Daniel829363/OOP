#include <iostream>
#include <string>
#include <ctime>
#include "Header.h"

class Timer {
private:
    int seconds;

public:
    // ����������� � ��������� ������� � �������� (����� �����)
    Timer(int sec) : seconds(sec) {}

    // ����������� � ��������� ������� � �������� (������)
    Timer(const std::string& time) {
        parseTimeString(time);
    }

    // ����������� � ��������� ������� � ������� � �������� (��� ����� �����)
    Timer(int minutes, int sec) : seconds(minutes * 60 + sec) {}

    // ������� ��� ������� �������
    void run() {
        while (seconds > 0) {
            std::cout << "�������� �������: " << seconds << " ������." << std::endl;
            std::cout << "���-���..." << std::endl;
            std::cout << std::endl;

            // �������� �������� 1 �������
            delay(1000);

            seconds--;
        }

        std::cout << "������! ����� �������." << std::endl;
    }

private:
    // ������� ��� ������� ������ ������� � ��������� ���������������� �������� � ��������
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

    // ������� ��� �������� �������� � �������������
    void delay(int milliseconds) {
        clock_t start_time = clock();
        while (clock() < start_time + milliseconds);
    }
};

int lab3z1() {
    // ������� ������������� ������ Timer
    int n;
    std::cout << "������� �����: ";
    std::cin >> n;
    Timer timer1(n);              
    /*Timer timer2("0:10");           
    Timer timer3(0, 15); */           

    timer1.run();
    /*timer2.run();
    timer3.run();*/

    return 0;
}
