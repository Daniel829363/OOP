#include <iostream>
using namespace std;

const int LIMIT = 100;

// Определение класса исключения
class OutOfRangeException {
public:
    OutOfRangeException(int index) {
        cout << "Ошибка: индекс " << index << " вне допустимого диапазона!" << endl;
    }
};

class safearray {
private:
    int arr[LIMIT];
public:
    void putel(int n, int elvalue) {
        if (n < 0 || n >= LIMIT) {
            throw OutOfRangeException(n); // Генерация исключения
        }
        arr[n] = elvalue;
    }

    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            throw OutOfRangeException(n); // Генерация исключения
        }
        return arr[n];
    }
};

int lab9z1() {
    safearray sal;

    try {
        // Задаем значения элементов
        for (int j = 0; j < LIMIT; j++) sal.putel(j, j * 10);
        // Показываем элементы
        for (int j = 0; j < LIMIT; j++) {
            int temp = sal.getel(j);
            cout << "Элемент " << j << " равен " << temp << endl;
        }
        // Попытка доступа к элементу вне диапазона
        sal.getel(LIMIT); // Это вызовет исключение
    }
    catch (OutOfRangeException& e) {
        // Обработка исключения
        // Сообщение об ошибке уже было выведено в конструкторе класса исключения
    }

    return 0;
}
