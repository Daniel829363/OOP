//#include <iostream>
//#include <string>
////#include "Header.h"
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
//};
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
//};
//
//int FrCreater(const Kamaz&, const Tatra&);
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    /*int n;
//hh:
//    std::cout << "������� ����� �������: ";
//    std::cin >> n;
//
//    if (n == 1);
//    else if (n == 2) {
//        lab4z2();
//        goto hh;
//    }
//    else if (n == 3) {
//        lab4z3();
//        goto hh;
//    }
//    else return 0;*/
//
//    Kamaz kamaz("Master", 120); // �������� � ��/�
//    Tatra tatra("Phoenix", 110);
//
//    // ����� ���������� � ����������
//    kamaz.display();
//    tatra.display();
//
//    // ��������� ���������
//    int result = FrCreater(kamaz, tatra);
//    if (result > 0)
//        std::cout << "Kamaz ������� Tatra." << std::endl;
//    else if (result == 0)
//        std::cout << "�������� Kamaz � Tatra ���������." << std::endl;
//    else
//        std::cout << "Tatra ������� Kamaz." << std::endl;
//
//    return 0;
//}
//
//int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
//    if (kamaz.getSpeed() > tatra.getSpeed())
//        return 1;
//    else if (kamaz.getSpeed() == tatra.getSpeed())
//        return 0;
//    else
//        return -1;
//}
