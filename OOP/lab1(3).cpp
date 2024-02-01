#include <iostream>
#include <vector>
#include "Header.h"
#include <Windows.h>

using namespace std;

// ��������� ��� ������������� ���������� � ���������
struct Worker {
    string surname;
    int age;
    string specialization;
    double averageSalary;
};

int lab1z3() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // ���� � ������� � ��������� 1251
    SetConsoleOutputCP(1251);

    int numFactories;
    cout << "������� ���������� �������: ";
    cin >> numFactories;

    vector<int> numLocksmiths(numFactories, 0);  // ������ ��� �������� ���������� �������� �� �������
    vector<int> numTurners(numFactories, 0);    // ������ ��� �������� ���������� ������� �� �������

    int sl = 0;
    int tk = 0;
    // ������ ��� �������� ���������� � ���������� �� �������
    vector<vector<Worker>> factoryWorkers(numFactories);

    // ���� ���������� � ����������
    for (int i = 0; i < numFactories; ++i) {
        int numWorkers;
        cout << "������� ���������� ���������� �� ������ " << (i + 1) << ": ";
        cin >> numWorkers;

        for (int j = 0; j < numWorkers; ++j) {
            Worker worker;
            cout << "������� ���������� � ��������� " << (j + 1) << " �� ������ " << (i + 1) << ":" << endl;
            cout << "�������: ";
            cin >> worker.surname;
            cout<< worker.surname<<endl;
            cout << "�������: ";
            cin >> worker.age;
            cout << "�������������: ";
            cin >> worker.specialization;
            cout << worker.specialization<<endl;
            cout << "������� �����: ";
            cin >> worker.averageSalary;

            // ������� �������� � �������
            if (worker.specialization == "�������") {
                sl++;
            }
            else if (worker.specialization == "������") {
                tk++;
            }

            factoryWorkers[i].push_back(worker);
        }
    }

    
    cout << "���������� ��������: " << sl << endl;
    cout << "���������� �������: " << tk << endl;
    return 0;
}
