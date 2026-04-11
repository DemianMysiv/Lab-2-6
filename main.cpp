#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <windows.h>
#include "IDisplayable.h"
#include "Employee.h"
#include "Project.h"

void userMenu() {
    std::cout << "\n--- МЕНЮ КОРИСТУВАЧА ---\n";
}

void adminMenu(std::vector<std::unique_ptr<IDisplayable>>& data) {
    int choice;
    do {
        std::cout << "\n1. ДОДАТИ працівника\n2. ДОДАТИ проєкт\n0. Вихід\nДія: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Ім'я: "; 
            std::cin >> name;
            data.push_back(std::make_unique<Employee>(name));
            std::cout << "Працівника додано!\n";
        } else if (choice == 2) {
            std::string title; 
            int d;
            std::cout << "Назва: "; 
            std::cin >> title;
            std::cout << "Тижні: "; 
            std::cin >> d;
            data.push_back(std::make_unique<Project>(title, d));
            std::cout << "Проєкт додано!\n";
        }
    } while(choice != 0);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::vector<std::unique_ptr<IDisplayable>> companyData;
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
                }
                break;
            }
            case 2: 
                userMenu(); 
                break;
            case 0: 
                std::cout << "Вихід...\n"; 
                break;
            default: 
                std::cout << "Помилка!\n";
        }
    } while(role != 0);

    return 0;
}