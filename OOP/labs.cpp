#include <iostream>
#include "Header.h"
#include <Windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    while (true) {
        cout << "������� ����� ����: ";
        cin >> n;

        switch (n)
        {
        case 1:lab1z12(); break;
        case 2:lab2(); break;
        default:break;
        }
    }
    return 0;
}
