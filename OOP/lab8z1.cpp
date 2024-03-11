#include <iostream>
#include <algorithm> // ��� std::sort

// ������ ������� ��� ���������� ������������� �������� �������
template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ������ ������� ��� ���������� �������
template <typename T>
void sortArray(T arr[], int size) {
    std::sort(arr, arr + size);
}

int lab8z1() {
    // ������ � �������� ����� �����
    int intArray[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "������������ ������� � intArray: " << findMax(intArray, intSize) << std::endl;
    sortArray(intArray, intSize);
    std::cout << "��������������� intArray: ";
    for (int n : intArray) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // ������ � �������� ��������
    char charArray[] = { 'C', '+', '+', 'R', 'o', 'c', 'k', 's', '!' };
    int charSize = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "������������ ������� � charArray: " << findMax(charArray, charSize) << std::endl;
    sortArray(charArray, charSize);
    std::cout << "��������������� charArray: ";
    for (char c : charArray) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
