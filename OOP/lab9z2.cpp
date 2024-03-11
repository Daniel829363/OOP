#include <iostream>
using namespace std;

// ������ ����������
class Kamaz;
class Tatra;

// ����� ����������
class SpeedComparisonException {
public:
    string message;
    SpeedComparisonException(string msg) : message(msg) {}
};

// ������� ��������� ���������
int FrCreater(const Kamaz& kamaz, const Tatra& tatra);

class Kamaz {
private:
    int speed;
    string name;
public:
    Kamaz(int sp, string nm) : speed(sp), name(nm) {}
    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
    void display() const {
        cout << "�����: " << name << ", ��������: " << speed << endl;
    }
};

class Tatra {
private:
    int speed;
    string name;
public:
    Tatra(int sp, string nm) : speed(sp), name(nm) {}
    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
    friend class Kamaz;
    void display() const {
        cout << "Tatra: " << name << ", ��������: " << speed << endl;
    }
};

int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.speed > tatra.speed) return 1;
    else if (kamaz.speed == tatra.speed) return 0;
    else return -1;
}

int lab9z2() {
    Kamaz kamaz(80, "�����-������");
    Tatra tatra(75, "Tatra Phoenix");

    try {
        int result = FrCreater(kamaz, tatra);
        kamaz.display();
        tatra.display();
        if (result == 1) {
            cout << "����������: �����" << endl;
        }
        else if (result == -1) {
            cout << "����������: Tatra" << endl;
        }
        else {
            throw SpeedComparisonException("�������� ���������� ���������");
        }
    }
    catch (SpeedComparisonException& e) {
        cout << "����������: " << e.message << endl;
    }

    return 0;
}
