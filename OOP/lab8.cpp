#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;

int lab8() {
    setlocale(LC_ALL, "rus");

    int n, i = 1;
    while (i != 0) {
        cout << "¬ведите номер задачи: ";
        cin >> n;

        switch (n)
        {
        case 1:lab8z1(); break;
        case 2:lab8z2(); break;
        case 3:lab8z3(); break;
        default:return 0;
        }
    }
    return 0;
}