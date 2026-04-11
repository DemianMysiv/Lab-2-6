#include <iostream>
#include <string>
#include <windows.h>

void userMenu() {
    std::cout << "\n--- МЕНЮ КОРИСТУВАЧА ---\n";
}

void adminMenu() {
    std::cout << "\n--- МЕНЮ АДМІНІСТРАТОРА ---\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

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
                    adminMenu(); 
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