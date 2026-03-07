#include "Department.h"

using namespace std;

Department::Department() : Department{ "Marketing", 0, 1, "Standard" } {
    cout << "Викликано конструктор за замовчуванням Department" << endl;
}

Department::Department(string name, int count) : Department{ name, count, 1, "Standard" } {
    cout << "Викликано конструктор Department з 2 параметрами" << endl;
}

Department::Department(string name, int count, int fl) : Department{ name, count, fl, "Standard" } {
    cout << "Викликано конструктор Department з 3 параметрами" << endl;
}

Department::Department(string name, int count, int fl, string res) 
    : deptName{ name }, employeecount{ count }, floor{ fl }, resources{ res } {
    cout << "Викликано основний конструктор ініціалізації Department" << endl;
}

Department::~Department() {
    cout << "Спрацював деструктор класу Department" << endl;
}

void Department::relocate(int newfloor) {
    floor = newfloor;
    cout << "Відділ " << deptName << " переїхав на " << floor << " поверх." << endl;
}

void Department::hireEmployee(int addedcount) {
    employeecount += addedcount;
    cout << "У відділ " << deptName << " найнято нових. Загальна кількість: " << employeecount << endl;
}

void Department::setResources(string newResources) {
    resources = newResources;
}