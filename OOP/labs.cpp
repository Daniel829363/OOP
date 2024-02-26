#include <iostream>
#include "Header.h"
#include <Windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n,i=1;
    while (i!=0) {
        cout << "¬ведите номер лабы: ";
        cin >> n;

        switch (n)
        {
        case 1:lab1z12(); break;
        case 2:lab2(); break;
        case 3:lab3z1(); break;
            //case 4:lab4z1(); break;
        case 5:lab5z1(); break;
        default:i = 0; break;
        }
    }
    return 0;
}
