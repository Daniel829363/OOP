#include <iostream>
#include <string>
#include <vector>

// Структура для хранения информации о работнике
struct Worker {
    std::string surname;
    int age;
    std::string specialty;
    double average_salary;
};

// Шаблон класса стек
template <typename T>
class Stack {
private:
    std::vector<T> elements; // Вектор для хранения элементов стека

public:
    // Поместить элемент в стек
    void push(const T& element) {
        elements.push_back(element);
    }

    // Удалить элемент из стека и вернуть его
    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): пустой стек");
        }
        T elem = elements.back();
        elements.pop_back();
        return elem;
    }

    // Посмотреть элемент на вершине стека
    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): пустой стек");
        }
        return elements.back();
    }

    // Проверка, пуст ли стек
    bool empty() const {
        return elements.empty();
    }

    // Получить размер стека
    size_t size() const {
        return elements.size();
    }
};

int lab8z3() {
    Stack<Worker> factoryStack; // Стек для хранения информации о работниках
    int numLocksmiths = 0; // Количество слесарей
    int numTurners = 0;    // Количество токарей

    // Добавление информации о работниках в стек (пример)
    factoryStack.push({ "Иванов", 30, "слесарь", 40000 });
    factoryStack.push({ "Петров", 40, "токарь", 45000 });
    factoryStack.push({ "Сидоров", 35, "инженер", 50000 });

    // Подсчет количества слесарей и токарей
    while (!factoryStack.empty()) {
        Worker worker = factoryStack.pop();
        if (worker.specialty == "слесарь") {
            numLocksmiths++;
        }
        else if (worker.specialty == "токарь") {
            numTurners++;
        }
    }

    // Вывод результатов на консоль
    std::cout << "Количество слесарей: " << numLocksmiths << std::endl;
    std::cout << "Количество токарей: " << numTurners << std::endl;

    return 0;
}
