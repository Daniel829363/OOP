#include <iostream>
#include "Header.h"
#include <Windows.h>


using namespace std;

// ������������ ������� power ��� double
double power(double n, int p) {
    double result = 1;
    if (p < 2) p = 2;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

// ���������� ��� char
double power(char n, int p) {
    // ���������, �������� �� ������ ������
    if (isdigit(n)) {
        // ���� ������ - �����, ����������� ��� � ������������� �������� � �������� � �������
        return power(static_cast<double>(n - '0'), p);
    }
    else {
        // ���� ������ �� �������� ������, ���������� ASCII-��� �������
        return power(static_cast<double>(n), p);
    }
}

// ���������� ��� short int
double power(short int n, int p) {
    return power(static_cast<double>(n), p);
}

// ���������� ��� long int
double power(long int n, int p) {
    return power(static_cast<double>(n), p);
}

// ���������� ��� float
double power(float n, int p) {
    return power(static_cast<double>(n), p);
}

int lab1z12() {
    setlocale(LC_ALL, "rus");
    

    double n_double;
    char n_char;
    short int n_short;
    long int n_long;
    float n_float;
    int p;

    cout << "������� ����� n (double): ";
    cin >> n_double;

    cout << "������� ����� n (char): ";
    cin >> n_char;

    cout << "������� ����� n (short int): ";
    cin >> n_short;

    cout << "������� ����� n (long int): ";
    cin >> n_long;

    cout << "������� ����� n (float): ";
    cin >> n_float;

    cout << "������� ����� p: ";
    cin >> p;

    cout << n_double << "^" << p << " = " << power(n_double, p) << endl;
    cout << "Symbol " << (isdigit(n_char) ? "is a number: " : "is not a number: ") << (isdigit(n_char) ? static_cast<double>(n_char - '0') : static_cast<double>(n_char));
    cout<< "^" << p << " = " << power(n_char, p) << endl;
    cout << n_short << "^" << p << " = " << power(n_short, p) << endl;
    cout << n_long << "^" << p << " = " << power(n_long, p) << endl;
    cout << n_float << "^" << p << " = " << power(n_float, p) << endl;

    lab1z3();
    return 0;
}
