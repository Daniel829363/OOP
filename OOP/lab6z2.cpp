#include <iostream>
#include <string>
#include "Header.h"

class Display {
private:
    std::string type;
    long colors;
    int x_resolution;
    int y_resolution;

public:
    // ����������� � �����������
    Display(const char* _type, long _colors, int _x_resolution, int _y_resolution)
        : colors(_colors), x_resolution(_x_resolution), y_resolution(_y_resolution) {
    }

    // ���������� ���������� � ������� �� �������
    void displayInfo() const {
        std::cout << "��� ��������: " << type << std::endl;
        std::cout << "���������� ������: " << colors << std::endl;
        std::cout << "���������� �� ��� x: " << x_resolution << std::endl;
        std::cout << "���������� �� ��� y: " << y_resolution << std::endl;
    }
};

class MotherBoard {
protected:
    int processor;
    int speed;
    int RAM;

public:
    // ����������� � �����������
    MotherBoard(int _processor, int _speed, int _RAM)
        : processor(_processor), speed(_speed), RAM(_RAM) {}

    // ���������� ���������� � ����������� ����� �� �������
    void displayInfo() const {
        std::cout << "��� ����������: " << processor << std::endl;
        std::cout << "�������� ����������: " << speed << " GHz" << std::endl;
        std::cout << "����� ����������� ������: " << RAM << " GB" << std::endl;
    }
};

class Computer : protected Display, private MotherBoard {
private:
    std::string name;
    int hard_disk;

public:
    // ����������� � �����������
    Computer(const char* _name, int _hard_disk, const char* _type, long _colors, int _x_resolution, int _y_resolution,
        int _processor, int _speed, int _RAM)
        : Display(_type, _colors, _x_resolution, _y_resolution), MotherBoard(_processor, _speed, _RAM),
        hard_disk(_hard_disk) {
    }

    // ����� ��� ����������� ���������� � ����������
    void Show() const {
        std::cout << "����� ����������: " << name << std::endl;
        Display::displayInfo(); // ����� displayInfo �� ������ Display
        MotherBoard::displayInfo(); // ����� displayInfo �� ������ MotherBoard
        std::cout << "����� �������� �����: " << hard_disk << " GB" << std::endl;
    }
};

int lab6z2() {
    // �������� ������� ������ Computer
    Computer myPC("ASUS", 512, "LED", 16777216, 1920, 1080, 4, 3, 16);

    // ����������� ���������� � ����������
    myPC.Show();

    return 0;
}
