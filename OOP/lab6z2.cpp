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
    // Конструктор с аргументами
    Display(const char* _type, long _colors, int _x_resolution, int _y_resolution)
        : colors(_colors), x_resolution(_x_resolution), y_resolution(_y_resolution) {
    }

    // Размещение информации о дисплее на консоли
    void displayInfo() const {
        std::cout << "Тип монитора: " << type << std::endl;
        std::cout << "Количество цветов: " << colors << std::endl;
        std::cout << "Разрешение по оси x: " << x_resolution << std::endl;
        std::cout << "Разрешение по оси y: " << y_resolution << std::endl;
    }
};

class MotherBoard {
protected:
    int processor;
    int speed;
    int RAM;

public:
    // Конструктор с аргументами
    MotherBoard(int _processor, int _speed, int _RAM)
        : processor(_processor), speed(_speed), RAM(_RAM) {}

    // Размещение информации о материнской плате на консоли
    void displayInfo() const {
        std::cout << "Тип процессора: " << processor << std::endl;
        std::cout << "Скорость процессора: " << speed << " GHz" << std::endl;
        std::cout << "Объем оперативной памяти: " << RAM << " GB" << std::endl;
    }
};

class Computer : protected Display, private MotherBoard {
private:
    std::string name;
    int hard_disk;

public:
    // Конструктор с аргументами
    Computer(const char* _name, int _hard_disk, const char* _type, long _colors, int _x_resolution, int _y_resolution,
        int _processor, int _speed, int _RAM)
        : Display(_type, _colors, _x_resolution, _y_resolution), MotherBoard(_processor, _speed, _RAM),
        hard_disk(_hard_disk) {
    }

    // Метод для отображения информации о компьютере
    void Show() const {
        std::cout << "Марка компьютера: " << name << std::endl;
        Display::displayInfo(); // Метод displayInfo из класса Display
        MotherBoard::displayInfo(); // Метод displayInfo из класса MotherBoard
        std::cout << "Объем жесткого диска: " << hard_disk << " GB" << std::endl;
    }
};

int lab6z2() {
    // Создание объекта класса Computer
    Computer myPC("ASUS", 512, "LED", 16777216, 1920, 1080, 4, 3, 16);

    // Отображение информации о компьютере
    myPC.Show();

    return 0;
}
