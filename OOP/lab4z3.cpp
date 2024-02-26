//#include <iostream>
//#include <string>
//#include "Header.h"
//
//class Kamaz; // Объявляем класс Kamaz, чтобы его можно было использовать в дружественной функции FrCreater()
//
//class Tatra {
//private:
//    std::string name;
//    double speed;
//
//public:
//    Tatra(const std::string& name, double speed) : name(name), speed(speed) {}
//
//    void display() const {
//        std::cout << "Tatra \"" << name << "\": " << speed << " км/ч" << std::endl;
//    }
//
//    double getSpeed() const {
//        return speed;
//    }
//
//    friend class Kamaz; // Дружественный класс
//};
//
//class Kamaz {
//private:
//    std::string name;
//    double speed;
//
//public:
//    Kamaz(const std::string& name, double speed) : name(name), speed(speed) {}
//
//    void display() const {
//        std::cout << "Kamaz \"" << name << "\": " << speed << " км/ч" << std::endl;
//    }
//
//    double getSpeed() const {
//        return speed;
//    }
//
//    int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
//        if (kamaz.speed > tatra.speed)
//            return 1;
//        else if (kamaz.speed == tatra.speed)
//            return 0;
//        else
//            return -1;
//    }
//};
//
//
//
//int lab4z3() {
//    Kamaz kamaz("Master", 120); // Скорость в км/ч
//    Tatra tatra("Phoenix", 110);
//
//    // Вывод информации о грузовиках
//    kamaz.display();
//    tatra.display();
//
//    // Сравнение скоростей
//    int result = kamaz.FrCreater(kamaz, tatra);
//    if (result > 0)
//        std::cout << "Kamaz быстрее Tatra." << std::endl;
//    else if (result == 0)
//        std::cout << "Скорости Kamaz и Tatra одинаковы." << std::endl;
//    else
//        std::cout << "Tatra быстрее Kamaz." << std::endl;
//
//    return 0;
//}
