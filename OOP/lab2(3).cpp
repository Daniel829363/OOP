#include <iostream>
#include <fstream>
#include <stack>
#include <string>

class TrainSortingNode {
private:
    std::stack<int> mainTrack;  // �������� �������
    std::stack<int> sideTrack1; // ������� ������� 1
    std::stack<int> sideTrack2; // ������� ������� 2

public:
    // ��������� ����� �� �������� �������
    void addToMainTrack(int wagon) {
        mainTrack.push(wagon);
    }

    // ����������� ������ � �������� ������� �� �������
    void sortTrain() {
        while (!mainTrack.empty()) {
            if (mainTrack.top() % 2 == 0) {
                sideTrack1.push(mainTrack.top());
            }
            else {
                sideTrack2.push(mainTrack.top());
            }
            mainTrack.pop();
        }
    }

    // ������� ��������� ���� �������
    void printTracks() const {
        std::cout << "�������� �������: ";
        printStack(mainTrack);
        std::cout << "������� ������� 1: ";
        printStack(sideTrack1);
        std::cout << "������� ������� 2: ";
        printStack(sideTrack2);
    }

private:
    // ��������������� ������� ��� ������ ����������� �����
    void printStack(const std::stack<int>& track) const {
        std::stack<int> temp = track;
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int lab2z3() {
    TrainSortingNode sortingNode;
    setlocale(LC_ALL, "rus");

    char source;
    int wagon;

    std::cout << "�������� �������� ������� (f - �� �����, k - � ����������): ";
    std::cin >> source;

    if (source == 'f') {
        std::ifstream inputFile(".//input.txt");
        if (!inputFile.is_open()) {
            std::cerr << "������ �������� ����� input.txt" << std::endl;
            return 1;
        }

        while (inputFile >> wagon) {
            sortingNode.addToMainTrack(wagon);
        }

        inputFile.close();
    }
    else if (source == 'k') {
        std::cout << "������� ������ (������� ����� ��-�������� ������ ��� ����������): ";
        while (std::cin >> wagon) {
            sortingNode.addToMainTrack(wagon);
        }

        // ������� �����
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
        std::cerr << "�������� ����� ���������." << std::endl;
        return 1;
    }

    sortingNode.sortTrain();
    sortingNode.printTracks();

    return 0;
}
