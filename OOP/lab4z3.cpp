//#include <iostream>
//#include <string>
//#include "Header.h"
//
//class Kamaz; // ��������� ����� Kamaz, ����� ��� ����� ���� ������������ � ������������� ������� FrCreater()
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
//        std::cout << "Tatra \"" << name << "\": " << speed << " ��/�" << std::endl;
//    }
//
//    double getSpeed() const {
//        return speed;
//    }
//
//    friend class Kamaz; // ������������� �����
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
//        std::cout << "Kamaz \"" << name << "\": " << speed << " ��/�" << std::endl;
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
//    Kamaz kamaz("Master", 120); // �������� � ��/�
//    Tatra tatra("Phoenix", 110);
//
//    // ����� ���������� � ����������
//    kamaz.display();
//    tatra.display();
//
//    // ��������� ���������
//    int result = kamaz.FrCreater(kamaz, tatra);
//    if (result > 0)
//        std::cout << "Kamaz ������� Tatra." << std::endl;
//    else if (result == 0)
//        std::cout << "�������� Kamaz � Tatra ���������." << std::endl;
//    else
//        std::cout << "Tatra ������� Kamaz." << std::endl;
//
//    return 0;
//}
