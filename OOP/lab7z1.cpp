#include <iostream>

const int MAX_SIZE = 100; // ������������ ������ �������

class Array {
public:
    unsigned arr[MAX_SIZE];
    int size;

public:
    // ����������� �������������
    Array(int _size, unsigned initValue = 0) : size(_size) {
        for (int i = 0; i < size; ++i) {
            arr[i] = initValue;
            initValue++;
        }
    }

    // ����������� ������� ������������� �������� ��������
    virtual void addElements(const Array& other) const {
        int minSize = std::min(size, other.size);
        for (int i = 0; i < minSize; ++i) {
            std::cout << arr[i] + other.arr[i] << " ";
        }
        for (int i = minSize; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        for (int i = minSize; i < other.size; ++i) {
            std::cout << other.arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

class ArrayDerived1 : public Array {
public:
    // �������� ����������� �������� ������ ��� ������������� �������
    ArrayDerived1(int _size, unsigned initValue = 0) : Array(_size, initValue) {}

    // ��������������� ����������� ������� ��� ������������� �������� ��������
    void addElements(const Array& other) const override {
        int minSize = std::min(size, other.size);
        for (int i = 0; i < minSize; ++i) {
            std::cout << arr[i] + other.arr[i] + 10 << " "; // ������ �������������� ��������� ��� ��������
        }
        for (int i = minSize; i < size; ++i) {
            std::cout << arr[i] + 10 << " ";
        }
        for (int i = minSize; i < other.size; ++i) {
            std::cout << other.arr[i] + 10 << " ";
        }
        std::cout << std::endl;
    }
};

class ArrayDerived2 : public Array {
public:
    // �������� ����������� �������� ������ ��� ������������� �������
    ArrayDerived2(int _size, unsigned initValue = 0) : Array(_size, initValue) {}

    // ��������������� ����������� ������� ��� ������������� �������� ��������
    void addElements(const Array& other) const override {
        int minSize = std::min(size, other.size);
        for (int i = 0; i < minSize; ++i) {
            std::cout << arr[i] + other.arr[i] - 5 << " "; // ������ �������������� ��������� ��� ��������
        }
        for (int i = minSize; i < size; ++i) {
            std::cout << arr[i] - 5 << " ";
        }
        for (int i = minSize; i < other.size; ++i) {
            std::cout << other.arr[i] - 5 << " ";
        }
        std::cout << std::endl;
    }
};

int lab7z1() {
    // ������� ������� ������ Array � ��� �������� �������
    Array arr1(5, 1);
    ArrayDerived1 arr2(5, 2);
    ArrayDerived2 arr3(7, 3);

    // �������� ����������� ������� ������������� �������� ��������
    arr1.addElements(arr2);
    arr2.addElements(arr3);
    arr3.addElements(arr1);

    return 0;
}
