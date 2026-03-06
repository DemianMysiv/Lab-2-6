#include "Employee.h"

using namespace std;

Employee::Employee() : fullName(""), idcardnumber(0), salary(0.0), position("") {
    cout << "Викликано конструктор за замовчуванням Employee" << endl;
}

Employee::Employee(string fullName) : fullName(fullName), idcardnumber(0), salary(0.0), position("") {
    cout << "Викликано конструктор для Employee з 1 параметром" << endl;
}

Employee::Employee(string fullName, int idcardnumber) 
    : fullName(fullName), idcardnumber(idcardnumber), salary(0.0), position("") {
    cout << "Викликано конструктор для Employee з 2 параметрами" << endl;
}

Employee::Employee(string fullName, int idcardnumber, double salary) 
    : fullName(fullName), idcardnumber(idcardnumber), salary(salary), position("") {
    cout << "Викликано конструктор для Employee з 3 параметрами" << endl;
}

Employee::Employee(string fullName, int idcardnumber, double salary, string position) 
    : fullName(fullName), idcardnumber(idcardnumber), salary(salary), position(position) {
    cout << "Викликано конструктор для Employee з 4 параметрами" << endl;
}

Employee::~Employee() {
    cout << "Спрацював деструктор класу Employee" << endl;
}

void Employee::promote(string newPosition) {
    position = newPosition;
}

void Employee::updateSalary(double bonus) {
    salary += bonus;
}

void Employee::showProfile() {
    cout << "Співробітник: " << fullName << ", Посада: " << position << endl;
}