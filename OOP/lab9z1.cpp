#include <iostream>
using namespace std;

const int LIMIT = 100;

// ����������� ������ ����������
class OutOfRangeException {
public:
    OutOfRangeException(int index) {
        cout << "������: ������ " << index << " ��� ����������� ���������!" << endl;
    }
};

class safearray {
private:
    int arr[LIMIT];
public:
    void putel(int n, int elvalue) {
        if (n < 0 || n >= LIMIT) {
            throw OutOfRangeException(n); // ��������� ����������
        }
        arr[n] = elvalue;
    }

    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            throw OutOfRangeException(n); // ��������� ����������
        }
        return arr[n];
    }
};

int lab9z1() {
    safearray sal;

    try {
        // ������ �������� ���������
        for (int j = 0; j < LIMIT; j++) sal.putel(j, j * 10);
        // ���������� ��������
        for (int j = 0; j < LIMIT; j++) {
            int temp = sal.getel(j);
            cout << "������� " << j << " ����� " << temp << endl;
        }
        // ������� ������� � �������� ��� ���������
        sal.getel(LIMIT); // ��� ������� ����������
    }
    catch (OutOfRangeException& e) {
        // ��������� ����������
        // ��������� �� ������ ��� ���� �������� � ������������ ������ ����������
    }

    return 0;
}
