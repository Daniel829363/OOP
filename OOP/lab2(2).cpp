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
    // ���������� ��������
    void addStudent(const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber) {
        students.emplace_back(lastName, dateOfBirth, phoneNumber);
    }

    // �������� �������� �� �������
    void removeStudent(const std::string& lastName) {
        students.erase(std::remove_if(students.begin(), students.end(), [lastName](const Student& student) {
            return student.lastName == lastName;
            }), students.end());
    }

    // ����� �������� �� �������
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

    // ���������� ��������� �� �������
    void sortByLastName() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
            });
    }

    // ����� ���������� � ���� ���������
    void printAllStudents() {
        if (students.empty()) {
            std::cout << "���� ������ ��������� �����." << std::endl;
            return;
        }

        std::cout << "-------------------------------------------------------------------------\n";
        std::cout << "| �������\t| ���� ��������\t| ����� ��������\t|\n";
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
        std::cout << "\n����:\n";
        std::cout << "1. �������� ��������\n";
        std::cout << "2. ������� ��������\n";
        std::cout << "3. ����� �������� �� �������\n";
        std::cout << "4. ����������� ��������� �� �������\n";
        std::cout << "5. ������� ���������� � ���� ���������\n";
        std::cout << "6. �����\n";
        std::cout << "�������� �������� (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "������� �������: ";
            std::cin >> lastName;
            std::cout << "������� ���� ��������: ";
            std::cin >> dateOfBirth;
            std::cout << "������� ����� ��������: ";
            std::cin >> phoneNumber;
            database.addStudent(lastName, dateOfBirth, phoneNumber);
            break;
        case '2':
            std::cout << "������� ������� �������� ��� ��������: ";
            std::cin >> lastName;
            database.removeStudent(lastName);
            break;
        case '3':
            std::cout << "������� ������� �������� ��� ������: ";
            std::cin >> lastName;
            {
                Student* foundStudent = database.findStudentByLastName(lastName);
                if (foundStudent != nullptr) {
                    std::cout << "������ �������:\n";
                    std::cout << "�������: " << foundStudent->lastName << "\n";
                    std::cout << "���� ��������: " << foundStudent->dateOfBirth << "\n";
                    std::cout << "����� ��������: " << foundStudent->phoneNumber << "\n";
                }
                else {
                    std::cout << "������� �� ������.\n";
                }
            }
            break;
        case '4':
            database.sortByLastName();
            std::cout << "�������� ������������� �� �������.\n";
            break;
        case '5':
            database.printAllStudents();
            break;
        case '6':
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "�������� ����. ��������� �������.\n";
        }
    } while (choice != '6');

    return 0;
}
