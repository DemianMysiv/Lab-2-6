#include <iostream>
#include "Employee.h"
#include "Project.h"
#include "Department.h"
#include <windows.h>
#include <vector>



int main() {
    SetConsoleOutputCP(CP_UTF8);

/*     Employee emp1("ZhalobaEduard");
    Employee emp2("DemyanMysiv", 797, 1000, "boss");

    emp1.showProfile();
    emp2.showProfile();  */

/*     Employee emp{"Іван Мельник", 101, 15000.5, "Менеджер"};
    std::cout << "Зарплата першого співробітника: " << emp.getSalary() << std::endl;

    std::vector<Employee> vectorOfEmployees(1, emp);

    vectorOfEmployees.emplace_back("Петро Петренко", 102, 12000.0, "Розробник");
    vectorOfEmployees.push_back(Employee{"Олена Коваленко", 103, 16000.0, "Дизайнер"});
    vectorOfEmployees.push_back(Employee{"Сергій Сидоренко", 104, 14000.0, "Аналітик"});
    vectorOfEmployees.push_back(Employee{"Марія Мельник", 105, 17000.0, "Керівник"});
    vectorOfEmployees.push_back(Employee{"Олексій Бондар", 106, 13000.0, "Тестувальник"});  */

/*      Department dep1;
    Department dep2("buchalteria", 100);

    dep1.hireEmployee(50);
    dep2.hireEmployee(50);

    Project prj1;

    prj1.getStatusOfProject();
    Project prj2(prj1); 
    prj2.getStatusOfProject();   */



/*     Employee emp1{"Іван Мельник", 101, 15000.0, "Менеджер"};
    Employee emp2{"Петро Петренко", 102, 12000.0, "Розробник"};


    emp1.WhoisthisP(emp2);
  */

    const Employee boss{"Віктор Петрович", 1, 50000.0, "Генеральний директор"};
    boss.showProfile();
    std::cout << "Зарплата: " << boss.getSalary() << std::endl;

    return 0;
}