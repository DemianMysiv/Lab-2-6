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

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Employee emp1("Іван Іванов", 12345, 50000.0, "Розробник");
    Manager boss("Олексій", 777, 4500.50, 12, "IT", "Senior Manager");
    showinformation(emp1);
    showinformation(boss);

    std::cout << std::endl;

    CompanyAsset asset("A001", 100000.0, 2020);
    Vehicle car("V001", 20000.0, 2021, "AA1234BB", 12000);
    RealEstate office("R001", 500000.0, 2019, "вул. Центральна, 1", 150.0);
    Financing(asset);
    Financing(car);
    Financing(office);


}