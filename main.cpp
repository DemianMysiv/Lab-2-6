#include <iostream>
#include "Employee.h"
#include "Project.h"
#include "Department.h"
#include <windows.h>
#include <vector>
#include "Developer.h"
#include "CompanyAsset.h"
#include "Manager.h"
#include "RealEstate.h"
#include "Vehicle.h"
#include "CodingTask.h"
#include "ProjectTask.h"

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

    //6 ЗАВДАННЯ
    
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


    Employee dev10("Demyan");
    Project startup("Pixel Point App", 50000);

    showOnDashboard(dev10);     
    showOnDashboard(startup);



/*     delete emp;
    delete boss;
    delete dev;

    delete asset;
    delete car;
    delete office;
     */
    return 0;
}