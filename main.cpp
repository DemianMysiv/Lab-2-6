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


void showinformation(const Employee &emp) {
    emp.showneededinfo();
}

void Financing(const CompanyAsset& asset) {
    std::cout << asset.calculateMaintenanceCosts() << std::endl;
}
void PayBonus(const Employee& emp) {
    std::cout << "Нараховано бонус: " << emp.calculateAnnualBonus() << " USD\n" << std::endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Employee emp1("Іван Іванов", 12345, 50000.0, "Розробник");
    Manager boss1("Олексій", 777, 4500.50, 12, "IT", "Senior Manager");
    showinformation(emp1);
    showinformation(boss1);


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
    
    
    delete emp;
    delete boss;
    delete dev;

    delete asset;
    delete car;
    delete office;
    
    return 0;


}