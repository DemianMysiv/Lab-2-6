#include <iostream>
#include "Employee.h"
#include "Project.h"
#include "Department.h"
#include <windows.h> // Додаємо цю бібліотеку для роботи з консоллю Windows

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Employee emp1("MysivDemian");
    Employee emp2("MysivDemyan", 797, 1000, "boss");

    emp1.showProfile();
    emp2.showProfile();

    Department dep1;
    Department dep2("buchalteria", 100);

    dep1.hireEmployee(50);
    dep2.hireEmployee(50);

    Project prj1;

    prj1.getStatusOfProject();
    Project prj2(prj1); 
    prj2.getStatusOfProject();

    return 0;
}