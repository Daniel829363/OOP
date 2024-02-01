#include <iostream>
#include <vector>
#include <algorithm>

class Student {
public:
    std::string lastName;
    std::string dateOfBirth;
    std::string phoneNumber;

    Student(const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber)
        : lastName(lastName), dateOfBirth(dateOfBirth), phoneNumber(phoneNumber) {}
};

class StudentDatabase {
private:
    std::vector<Student> students;

public:
    // Добавление студента
    void addStudent(const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber) {
        students.emplace_back(lastName, dateOfBirth, phoneNumber);
    }

    // Удаление студента по фамилии
    void removeStudent(const std::string& lastName) {
        students.erase(std::remove_if(students.begin(), students.end(), [lastName](const Student& student) {
            return student.lastName == lastName;
            }), students.end());
    }

    // Поиск студента по фамилии
    Student* findStudentByLastName(const std::string& lastName) {
        auto it = std::find_if(students.begin(), students.end(), [lastName](const Student& student) {
            return student.lastName == lastName;
            });

        if (it != students.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }

    // Сортировка студентов по фамилии
    void sortByLastName() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
            });
    }

    // Вывод информации о всех студентах
    void printAllStudents() {
        if (students.empty()) {
            std::cout << "База данных студентов пуста." << std::endl;
            return;
        }

        std::cout << "-------------------------------------------------------------------------\n";
        std::cout << "| Фамилия\t| Дата рождения\t| Номер телефона\t|\n";
        std::cout << "-------------------------------------------------------------------------\n";

        for (const auto& student : students) {
            std::cout << "| " << student.lastName << "\t\t| " << student.dateOfBirth << "\t\t| " << student.phoneNumber << "\t\t|\n";
        }

        std::cout << "-------------------------------------------------------------------------\n";
    }
};

int lab2z2() {
    StudentDatabase database;

    char choice;
    std::string lastName, dateOfBirth, phoneNumber;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Удалить студента\n";
        std::cout << "3. Найти студента по фамилии\n";
        std::cout << "4. Сортировать студентов по фамилии\n";
        std::cout << "5. Вывести информацию о всех студентах\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите действие (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "Введите фамилию: ";
            std::cin >> lastName;
            std::cout << "Введите дату рождения: ";
            std::cin >> dateOfBirth;
            std::cout << "Введите номер телефона: ";
            std::cin >> phoneNumber;
            database.addStudent(lastName, dateOfBirth, phoneNumber);
            break;
        case '2':
            std::cout << "Введите фамилию студента для удаления: ";
            std::cin >> lastName;
            database.removeStudent(lastName);
            break;
        case '3':
            std::cout << "Введите фамилию студента для поиска: ";
            std::cin >> lastName;
            {
                Student* foundStudent = database.findStudentByLastName(lastName);
                if (foundStudent != nullptr) {
                    std::cout << "Найден студент:\n";
                    std::cout << "Фамилия: " << foundStudent->lastName << "\n";
                    std::cout << "Дата рождения: " << foundStudent->dateOfBirth << "\n";
                    std::cout << "Номер телефона: " << foundStudent->phoneNumber << "\n";
                }
                else {
                    std::cout << "Студент не найден.\n";
                }
            }
            break;
        case '4':
            database.sortByLastName();
            std::cout << "Студенты отсортированы по фамилии.\n";
            break;
        case '5':
            database.printAllStudents();
            break;
        case '6':
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный ввод. Повторите попытку.\n";
        }
    } while (choice != '6');

    return 0;
}
