#include <iostream>
#include <vector>
#include "Header.h"
#include <Windows.h>

using namespace std;

// Структура для представления информации о работнике
struct Worker {
    string surname;
    int age;
    string specialization;
    double averageSalary;
};

int lab1z3() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);

    int numFactories;
    cout << "Введите количество заводов: ";
    cin >> numFactories;

    vector<int> numLocksmiths(numFactories, 0);  // Вектор для хранения количества слесарей по заводам
    vector<int> numTurners(numFactories, 0);    // Вектор для хранения количества токарей по заводам

    int sl = 0;
    int tk = 0;
    // Вектор для хранения информации о работниках по заводам
    vector<vector<Worker>> factoryWorkers(numFactories);

    // Ввод информации о работниках
    for (int i = 0; i < numFactories; ++i) {
        int numWorkers;
        cout << "Введите количество работников на заводе " << (i + 1) << ": ";
        cin >> numWorkers;

        for (int j = 0; j < numWorkers; ++j) {
            Worker worker;
            cout << "Введите информацию о работнике " << (j + 1) << " на заводе " << (i + 1) << ":" << endl;
            cout << "Фамилия: ";
            cin >> worker.surname;
            cout<< worker.surname<<endl;
            cout << "Возраст: ";
            cin >> worker.age;
            cout << "Специальность: ";
            cin >> worker.specialization;
            cout << worker.specialization<<endl;
            cout << "Средний оклад: ";
            cin >> worker.averageSalary;

            // Подсчет слесарей и токарей
            if (worker.specialization == "слесарь") {
                sl++;
            }
            else if (worker.specialization == "токарь") {
                tk++;
            }

            factoryWorkers[i].push_back(worker);
        }
    }

    
    cout << "Количество слесарей: " << sl << endl;
    cout << "Количество токарей: " << tk << endl;
    return 0;
}
