#include <iostream>
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
    do {
        std::cout << "\n=== ВИБІР РОЛІ ===\n";
        std::cout << "1. Адміністратор\n";
        std::cout << "2. Користувач\n";
        std::cout << "0. Вихід\n";
        std::cout << "Оберіть роль: ";
        std::cin >> role;

        switch(role) {
            case 1: 
                adminMenu(); 
                break;
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