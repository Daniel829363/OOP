#include <iostream>
#include "Header.h"
#include <Windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    while (true) {
        cout << "¬ведите номер лабы: ";
        cin >> n;

        switch (n)
        {
        case 1:lab1z12(); break;
        case 2:lab2(); break;
        case 3:lab3z1(); break;
        default:break;
        }
    }
    return 0;
}
