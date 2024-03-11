#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;

int lab7() {
    setlocale(LC_ALL, "rus");

    int n, i = 1;
    while (i != 0) {
        cout << "¬ведите номер задачи: ";
        cin >> n;

        switch (n)
        {
        case 1:lab7z1(); break;
        case 2:lab7z2(); break;
        case 3:lab7z3(); break;
        default:return 0;
        }
    }
    return 0;
}