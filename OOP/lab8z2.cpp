#include <iostream>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime>   // ��� std::time

// ������ ������ � ����� ���������
template <typename T, int size>
class ArrayPair {
private:
    T array1[size];
    T array2[size];

public:
    // ����������� ��������� ������� ���������� �������
    ArrayPair() {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // ������������� ���������� ��������� �����
        for (int i = 0; i < size; ++i) {
            array1[i] = static_cast<T>(std::rand() % 100); // ��������� �������� �� 0 �� 99
            array2[i] = static_cast<T>(std::rand() % 100);
        }
    }

    // ������� ��� ������ ��������
    void printArrays() const {
        std::cout << "Array 1: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array1[i] << " ";
        }
        std::cout << "\nArray 2: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array2[i] << " ";
        }
        std::cout << std::endl;
    }

    // ������� ��� ���������� ����� ��������� ��������
    T sumArrays() const {
        T sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += array1[i] + array2[i];
        }
        return sum;
    }
};

int lab8z2() {
    // �������� ������� ��� int
    ArrayPair<int, 10> intPair;
    intPair.printArrays();
    std::cout << "����� ���������: " << intPair.sumArrays() << std::endl;

    // �������� ������� ��� double
    ArrayPair<double, 10> doublePair;
    doublePair.printArrays();
    std::cout << "����� ���������: " << doublePair.sumArrays() << std::endl;

    return 0;
}
