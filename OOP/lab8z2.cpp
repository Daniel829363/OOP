#include <iostream>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime>   // Для std::time

// Шаблон класса с двумя массивами
template <typename T, int size>
class ArrayPair {
private:
    T array1[size];
    T array2[size];

public:
    // Конструктор заполняет массивы случайными числами
    ArrayPair() {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // Инициализация генератора случайных чисел
        for (int i = 0; i < size; ++i) {
            array1[i] = static_cast<T>(std::rand() % 100); // Примерный диапазон от 0 до 99
            array2[i] = static_cast<T>(std::rand() % 100);
        }
    }

    // Функция для вывода массивов
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

    // Функция для нахождения суммы элементов массивов
    T sumArrays() const {
        T sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += array1[i] + array2[i];
        }
        return sum;
    }
};

int lab8z2() {
    // Создание объекта для int
    ArrayPair<int, 10> intPair;
    intPair.printArrays();
    std::cout << "Сумма элементов: " << intPair.sumArrays() << std::endl;

    // Создание объекта для double
    ArrayPair<double, 10> doublePair;
    doublePair.printArrays();
    std::cout << "Сумма элементов: " << doublePair.sumArrays() << std::endl;

    return 0;
}
