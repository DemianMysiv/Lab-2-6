#include <iostream>

#include <string>
#include <fstream>
#include <windows.h>
#include <memory>
#include <vector>


#include "IDisplayable.h"
#include "Employee.h"
#include "Project.h"
#include "Department.h"
#include "Developer.h"
#include "CompanyAsset.h"
#include "Manager.h"
#include "RealEstate.h"
#include "Vehicle.h"
#include "CodingTask.h"
#include "ProjectTask.h"



// Forward declarations

void adminMenu();
void userMenu();




//1

void showinformation(Employee &emp) {

    emp.showneededinfo();

}



//2 і 3

void printBonus(const Employee &e) {
    std::cout << "Нарахований бонус: " << e.calculateAnnualBonus() << " USD\n";

}

void Financing(const CompanyAsset& asset) {
    std::cout << asset.calculateMaintenanceCosts() << std::endl;

}



void showOnDashboard(const IDisplayable& item) {
    std::cout << "--- Оновлення дашборду ---" << std::endl;
    item.display();
    std::cout << "--------------------------" << std::endl;
}








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

        }

        else if (type == "Project") {

            std::string title;
            int duration;
            file >> title >> duration;

            data.push_back(std::make_unique<Project>(title, duration));
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
    logAction("Успішний вхід: Користувач (Гість)");

    do {

        std::cout << "\n--- МЕНЮ КОРИСТУВАЧА (Гостьовий доступ) ---\n";
        std::cout << "1. Переглянути загальний Дашборд\n";
        std::cout << "2. Переглянути послуги компанії\n";
        std::cout << "0. Повернутися до вибору ролі\n";
        std::cout << "Оберіть дію: ";
        std::cin >> choice;

        switch(choice) {

            case 1:
                std::cout << "\n[Завантаження Дашборду...]\n";
                viewDashboard(data);
                logAction("Користувач переглянув дашборд.");
                break;

            case 2:

                std::cout << "\n--- Наші експертні послуги ---\n";
                std::cout << "- E-commerce Suite\n- Web development\n- UI/UX Audit\n";
                logAction("Користувач переглянув послуги компанії.");
                break;

            case 0:

                std::cout << "Повернення...\n";
                logAction("Користувач вийшов з меню.");
                break;

            default:
                std::cout << "Невірний вибір!\n";
        }

    } while(choice != 0);

}



void adminMenu(std::vector<std::unique_ptr<IDisplayable>>& data) {
    int choice;
    logAction("Успішний вхід: Адміністратор");

    do {
        std::cout << "\n--- МЕНЮ АДМІНІСТРАТОРА ---\n";
        std::cout << "1. Показати Дашборд компанії\n";
        std::cout << "2. ДОДАТИ нового працівника\n";
        std::cout << "3. ДОДАТИ новий проєкт\n";
        std::cout << "0. Повернутися до вибору ролі\n";
        std::cout << "Оберіть дію: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                viewDashboard(data);
                logAction("Адміністратор переглянув дашборд.");
                break;

            case 2: {
                std::string name;
                std::cout << "Введіть ім'я нового працівника: ";
                std::cin >> name;

                try {
                    if (name.length() < 2) {
                        throw "Помилка! Ім'я працівника занадто коротке!"; 
                    }
                    
                    data.push_back(std::make_unique<Employee>(name));
                    saveToFile(data);

                    logAction("Адміністратор додав працівника: " + name);
                    std::cout << "-> Працівника успішно додано!\n";
                }
                catch (const char* error_message) {
                    std::cout << error_message << "\n";
                    logAction(std::string("Помилка при додаванні працівника: ") + error_message);
                }
                break;
            }

            case 3: {
                std::string title;
                int duration;

                std::cout << "Введіть назву проєкту: ";
                std::cin >> title;
                std::cout << "Введіть дедлайн (у тижнях): ";
                std::cin >> duration;

                try {
                    if (title.length() < 3) {
                        throw "Помилка! Назва проєкту має містити хоча б 3 символи!";
                    }

                    if (duration <= 0) {
                        throw "Помилка! Дедлайн має бути більшим за нуль!";
                    }

                    data.push_back(std::make_unique<Project>(title, duration));
                    saveToFile(data);
 
                    logAction("Адміністратор додав проєкт: " + title);
                    std::cout << "-> Проєкт успішно створено!\n";
                }

                catch (const char* error_message) {
                    std::cout << error_message << "\n";
                    logAction(std::string("Помилка при додаванні проєкту: ") + error_message);
                }
                break;
            }

            case 0:
                std::cout << "Повернення...\n";
                logAction("Адміністратор вийшов з меню.");
                break;

            default:
                std::cout << "Невірний вибір!\n";
                logAction("Помилка: невірний вибір меню адміністратора.");
        }
    } while(choice != 0);
}





int main() {

    SetConsoleOutputCP(CP_UTF8);



/*  Employee emp1("Іван Іванов", 12345, 50000.0, "Розробник");

    Manager boss1("Олексій", 777, 4500.50, 12, "IT", "Senior Manager");

    showinformation(emp1);

    showinformation(boss1);



//2 і 3.

    Employee *emp = new Employee("Іван Іванов", 12345, 50000.0, "Розробник");

    Employee *boss = new Manager("Олексій", 777, 4500.50, 12, "IT", "Senior Manager");

    Employee *dev = new Developer("Микола", 111, 60000.0, "Junior Developer", "C++", "https://github.com/nikolay");



   

    emp->calculateAnnualBonus();

    boss->calculateAnnualBonus();

    dev->calculateAnnualBonus();





    std::cout << std::endl;

    CompanyAsset* asset = new CompanyAsset("A001", 100000.0, 2020);

    CompanyAsset* car = new Vehicle("V001", 20000.0, 2021, "AA1234BB", 12000);

    CompanyAsset* office = new RealEstate("R001", 500000.0, 2019, "вул. Центральна, 1", 150.0);



    asset->calculateMaintenanceCosts();

    car->calculateMaintenanceCosts();

    office->calculateMaintenanceCosts();





    std::cout << std::endl;

 */



/*     //6 ЗАВДАННЯ

   

    Employee Pavlo("Павло", 101, 40000.0, "QA Engineer");

    const Employee &rPavlo = Pavlo;

    std::cout << "Бонус: " << rPavlo.calculateAnnualBonus() << " USD\n";



    Manager Demian("Дем'ян", 102, 85000.0, 4, "Pixel Point", "CEO");

    const Employee &rDemian = Demian;

    std::cout << "Бонус: " << rDemian.calculateAnnualBonus() << " USD\n";



    std::cout << std::endl;

   

    Employee Yaroslav("Ярослав", 103, 45000.0, "UX/UI Designer");

    Developer Vlad("Влад", 104, 70000.0, "Fullstack", "JS", "https://github.com/vlad");



    printBonus(Yaroslav);

    printBonus(Vlad);

   

    std::cout << std::endl;



    Employee *pEduard = new Developer("Едуард", 105, 75000.0, "Lead", "C++", "https://github.com/eduard");

    printBonus(*pEduard);

    delete pEduard;

 

    // ProjectTask task("Error", 5);        // Помилка! Абстрактний клас

    // ProjectTask* p = new ProjectTask();  // Помилка! Абстрактний клас



    ProjectTask* task = new CodingTask("Fix Bug", 5, 2);



    std::cout << "Task: " << task->getTitle() << std::endl;

    std::cout << "Priority: " << task->calculatePriority() << std::endl;



    delete task;





 */



/*     delete emp;

    delete boss;

    delete dev;



    delete asset;

    delete car;

    delete office;

     */


std::vector<std::unique_ptr<IDisplayable>> companyData;
    loadFromFile(companyData);
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

                try {

                    if (inputPass != ADMIN_PASS) {
                        logAction("Невдала спроба входу адміністратора.");
                        throw "Відмова в доступі! Невірний пароль!";
                    }

                    // Якщо пароль правильний:
                    adminMenu(companyData);
                }

                catch (const char* error_message) {
                    // Ловимо помилку
                    std::cout << error_message << "\n";
                }
                break;
            }

            case 2:
                userMenu(companyData);
                break;
            case 0:
                std::cout << "Вихід...\n";
                logAction("Програму закрито.");
                break;
            default:
                std::cout << "Помилка!\n";
        }
    } while(role != 0);

    return 0;

}

