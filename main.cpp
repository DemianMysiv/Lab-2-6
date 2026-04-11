#include <iostream>
#include <windows.h>

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
            case 1: std::cout << "Вхід для адміна...\n"; break;
            case 2: std::cout << "Вхід для користувача...\n"; break;
            case 0: std::cout << "Вихід...\n"; break;
            default: std::cout << "Помилка!\n";
        }
    } while(role != 0);

    return 0;
}