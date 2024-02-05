#include <iostream>
#include <string>
#include <chrono>
#include "Header.h"

class Soft {
private:
    std::string programName;
    std::string developer;
    double occupiedSpace; // объем в мегабайтах
    std::chrono::system_clock::time_point licenseExpirationDate;

public:
    // Конструктор по умолчанию
    Soft() : programName(""), developer(""), occupiedSpace(0.0) {
        // Установим дату завершения лицензии на один месяц вперед от текущей даты
        licenseExpirationDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 30);
    }

    // Конструктор с параметрами
    Soft(const std::string& name, const std::string& dev, double space, const std::chrono::system_clock::time_point& expirationDate)
        : programName(name), developer(dev), occupiedSpace(space), licenseExpirationDate(expirationDate) {}

    // Деструктор
    ~Soft() {
        std::cout << "Программное обеспечение \"" << programName << "\" удалено." << std::endl;
    }

    // Функция для подсчета количества дней до завершения лицензии
    int daysUntilExpiration() const {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::chrono::duration<int> daysDifference = std::chrono::duration_cast<std::chrono::duration<int>>(licenseExpirationDate - now);
        return daysDifference.count();
    }

    // Функция для вывода данных о программном обеспечении на экран
    void displaySoftwareDetails() const {
        std::cout << "Название программы: " << programName << std::endl;
        std::cout << "Разработчик: " << developer << std::endl;
        std::cout << "Занимаемый объем: " << occupiedSpace << " МБ" << std::endl;
        std::cout << "Дата завершения лицензии: " << daysUntilExpiration() << " дней" << std::endl;
    }
};

int lab3z3() {
    // Пример использования класса Soft
    std::chrono::system_clock::time_point expirationDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 60); // Лицензия на 2 месяца
    Soft software1("Microsoft Office", "Microsoft", 500, expirationDate);

    // Вывод данных о программном обеспечении
    software1.displaySoftwareDetails();

    return 0;
}
