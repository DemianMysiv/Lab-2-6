#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <windows.h>
#include "IDisplayable.h"
#include "Employee.h"
#include "Project.h"

void logAction(const std::string& action) {
    std::ofstream logFile("history.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << action << "\n";
        logFile.close();
    }
}

void saveToFile(const std::vector<std::unique_ptr<IDisplayable>>& data) {
    std::ofstream file("database.txt");
    for (size_t i = 0; i < data.size(); i++) {
        file << data[i]->toFileString() << "\n";
    }
    file.close();
}

void loadFromFile(std::vector<std::unique_ptr<IDisplayable>>& data) {
    std::ifstream file("database.txt");
    if (!file.is_open()) return;

    std::string type;
    while (file >> type) {
        if (type == "Employee") {
            std::string name; 
            file >> name;
            data.push_back(std::make_unique<Employee>(name));
        } else if (type == "Project") {
            std::string title; 
            int d; 
            file >> title >> d;
            data.push_back(std::make_unique<Project>(title, d));
        }
    }
    file.close();
}

void viewDashboard(const std::vector<std::unique_ptr<IDisplayable>>& data) {
    if (data.empty()) {
        std::cout << "Дашборд порожній. Адміністратор ще нічого не додав.\n"; 
        return;
    }
    for (size_t i = 0; i < data.size(); i++) {
        data[i]->display();
    }
}

void userMenu(const std::vector<std::unique_ptr<IDisplayable>>& data) {
    int choice;
    logAction("Успішний вхід: Користувач");
    do {
        std::cout << "\n--- МЕНЮ КОРИСТУВАЧА ---\n";
        std::cout << "1. Переглянути Дашборд\n0. Вихід\nДія: ";
        std::cin >> choice;
        if (choice == 1) {
            viewDashboard(data);
            logAction("Користувач переглянув дашборд");
        }
    } while(choice != 0);
}

void adminMenu(std::vector<std::unique_ptr<IDisplayable>>& data) {
    int choice;
    logAction("Успішний вхід: Адміністратор");
    do {
        std::cout << "\n--- МЕНЮ АДМІНІСТРАТОРА ---\n";
        std::cout << "1. Переглянути Дашборд\n2. ДОДАТИ працівника\n3. ДОДАТИ проєкт\n0. Вихід\nДія: ";
        std::cin >> choice;

        if (choice == 1) {
            viewDashboard(data);
            logAction("Адміністратор переглянув дашборд");
        } else if (choice == 2) {
            std::string name;
            std::cout << "Ім'я: "; 
            std::cin >> name;
            data.push_back(std::make_unique<Employee>(name));
            saveToFile(data);
            logAction("Додано працівника: " + name);
            std::cout << "Працівника додано!\n";
        } else if (choice == 3) {
            std::string title; 
            int d;
            std::cout << "Назва: "; 
            std::cin >> title;
            std::cout << "Тижні: "; 
            std::cin >> d;
            data.push_back(std::make_unique<Project>(title, d));
            saveToFile(data);
            logAction("Додано проєкт: " + title);
            std::cout << "Проєкт додано!\n";
        }
    } while(choice != 0);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::vector<std::unique_ptr<IDisplayable>> companyData;
    loadFromFile(companyData);

    if (!companyData.empty()) {
        std::cout << "[Система] Успішно відновлено " << companyData.size() << " записів з бази даних.\n";
    }

    int role;
    const std::string ADMIN_PASS = "1234";

    do {
        std::cout << "\n=== ВИБІР РОЛІ ===\n";
        std::cout << "1. Адміністратор\n";
        std::cout << "2. Користувач\n";
        std::cout << "0. Вихід\n";
        std::cout << "Оберіть роль: ";
        std::cin >> role;

        switch(role) {
            case 1: {
                std::string inputPass;
                std::cout << "Введіть пароль: ";
                std::cin >> inputPass;
                if (inputPass == ADMIN_PASS) {
                    adminMenu(companyData); 
                } else {
                    std::cout << "Відмова в доступі! Невірний пароль!\n";
                    logAction("Невдала спроба входу адміністратора");
                }
                break;
            }
            case 2: 
                userMenu(companyData); 
                break;
            case 0: 
                std::cout << "Вихід...\n"; 
                logAction("Програму закрито");
                break;
            default: 
                std::cout << "Помилка!\n";
        }
    } while(role != 0);

    return 0;
}