#include <iostream>
#include <fstream>
#include <stack>
#include <string>

class TrainSortingNode {
private:
    std::stack<int> mainTrack;  // Основная дорожка
    std::stack<int> sideTrack1; // Боковая дорожка 1
    std::stack<int> sideTrack2; // Боковая дорожка 2

public:
    // Поместить вагон на основную дорожку
    void addToMainTrack(int wagon) {
        mainTrack.push(wagon);
    }

    // Переместить вагоны с основной дорожки на боковые
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

    // Вывести состояние всех дорожек
    void printTracks() const {
        std::cout << "Основная дорожка: ";
        printStack(mainTrack);
        std::cout << "Боковая дорожка 1: ";
        printStack(sideTrack1);
        std::cout << "Боковая дорожка 2: ";
        printStack(sideTrack2);
    }

private:
    // Вспомогательная функция для вывода содержимого стека
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

    std::cout << "Выберите источник вагонов (f - из файла, k - с клавиатуры): ";
    std::cin >> source;

    if (source == 'f') {
        std::ifstream inputFile(".//input.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Ошибка открытия файла input.txt" << std::endl;
            return 1;
        }

        while (inputFile >> wagon) {
            sortingNode.addToMainTrack(wagon);
        }

        inputFile.close();
    }
    else if (source == 'k') {
        std::cout << "Введите вагоны (введите любой не-числовой символ для завершения): ";
        while (std::cin >> wagon) {
            sortingNode.addToMainTrack(wagon);
        }

        // Очистка ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
        std::cerr << "Неверный выбор источника." << std::endl;
        return 1;
    }

    sortingNode.sortTrain();
    sortingNode.printTracks();

    return 0;
}
