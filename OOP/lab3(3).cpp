#include <iostream>
#include <string>
#include <chrono>
#include "Header.h"

class Soft {
private:
    std::string programName;
    std::string developer;
    double occupiedSpace; // ����� � ����������
    std::chrono::system_clock::time_point licenseExpirationDate;

public:
    // ����������� �� ���������
    Soft() : programName(""), developer(""), occupiedSpace(0.0) {
        // ��������� ���� ���������� �������� �� ���� ����� ������ �� ������� ����
        licenseExpirationDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 30);
    }

    // ����������� � �����������
    Soft(const std::string& name, const std::string& dev, double space, const std::chrono::system_clock::time_point& expirationDate)
        : programName(name), developer(dev), occupiedSpace(space), licenseExpirationDate(expirationDate) {}

    // ����������
    ~Soft() {
        std::cout << "����������� ����������� \"" << programName << "\" �������." << std::endl;
    }

    // ������� ��� �������� ���������� ���� �� ���������� ��������
    int daysUntilExpiration() const {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::chrono::duration<int> daysDifference = std::chrono::duration_cast<std::chrono::duration<int>>(licenseExpirationDate - now);
        return daysDifference.count();
    }

    // ������� ��� ������ ������ � ����������� ����������� �� �����
    void displaySoftwareDetails() const {
        std::cout << "�������� ���������: " << programName << std::endl;
        std::cout << "�����������: " << developer << std::endl;
        std::cout << "���������� �����: " << occupiedSpace << " ��" << std::endl;
        std::cout << "���� ���������� ��������: " << daysUntilExpiration() << " ����" << std::endl;
    }
};

int lab3z3() {
    // ������ ������������� ������ Soft
    std::chrono::system_clock::time_point expirationDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 60); // �������� �� 2 ������
    Soft software1("Microsoft Office", "Microsoft", 500, expirationDate);

    // ����� ������ � ����������� �����������
    software1.displaySoftwareDetails();

    return 0;
}
