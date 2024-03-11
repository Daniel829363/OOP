#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;

int lab9() {
    setlocale(LC_ALL, "rus");

    int n, i = 1;
    while (i != 0) {
        cout << "¬ведите номер задачи: ";
        cin >> n;

        switch (n)
        {
        case 1:break;//lab9z1(); 
        case 2://lab9z2(); break;
        default:return 0;
        }
    }
    return 0;
}