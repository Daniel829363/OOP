#include <iostream>
#include <string>
#include <vector>

// ��������� ��� �������� ���������� � ���������
struct Worker {
    std::string surname;
    int age;
    std::string specialty;
    double average_salary;
};

// ������ ������ ����
template <typename T>
class Stack {
private:
    std::vector<T> elements; // ������ ��� �������� ��������� �����

public:
    // ��������� ������� � ����
    void push(const T& element) {
        elements.push_back(element);
    }

    // ������� ������� �� ����� � ������� ���
    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): ������ ����");
        }
        T elem = elements.back();
        elements.pop_back();
        return elem;
    }

    // ���������� ������� �� ������� �����
    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): ������ ����");
        }
        return elements.back();
    }

    // ��������, ���� �� ����
    bool empty() const {
        return elements.empty();
    }

    // �������� ������ �����
    size_t size() const {
        return elements.size();
    }
};

int lab8z3() {
    Stack<Worker> factoryStack; // ���� ��� �������� ���������� � ����������
    int numLocksmiths = 0; // ���������� ��������
    int numTurners = 0;    // ���������� �������

    // ���������� ���������� � ���������� � ���� (������)
    factoryStack.push({ "������", 30, "�������", 40000 });
    factoryStack.push({ "������", 40, "������", 45000 });
    factoryStack.push({ "�������", 35, "�������", 50000 });

    // ������� ���������� �������� � �������
    while (!factoryStack.empty()) {
        Worker worker = factoryStack.pop();
        if (worker.specialty == "�������") {
            numLocksmiths++;
        }
        else if (worker.specialty == "������") {
            numTurners++;
        }
    }

    // ����� ����������� �� �������
    std::cout << "���������� ��������: " << numLocksmiths << std::endl;
    std::cout << "���������� �������: " << numTurners << std::endl;

    return 0;
}
