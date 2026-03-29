#include <iostream>
#include "Employee.h"
#include "Project.h"
#include "Department.h"
#include <windows.h>
#include <vector>
#include "Developer.h"
#include "CompanyAsset.h"
#include "Manager.h"

void showinformation(const Employee &emp) {
    emp.showneededinfo();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Employee emp1("Іван Іванов", 12345, 50000.0, "Розробник");
    Manager boss("Олексій", 777, 4500.50, 12, "IT", "Senior Manager");
    showinformation(emp1);
    showinformation(boss);

}