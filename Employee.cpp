#include "Employee.h"

using namespace std;

Employee::Employee() : fullName(""), idcardnumber(0), position("") {
    salary = new double;
    *salary = 0.0;
    cout << "Викликано конструктор за замовчуванням Employee" << endl;
}

Employee::Employee(string fullName) : fullName(fullName), idcardnumber(0), position("") {
    salary = new double;
    *salary = 0.0;
    cout << "Викликано конструктор для Employee з 1 параметром" << endl;
}

Employee::Employee(string fullName, int idcardnumber) 
    : fullName(fullName), idcardnumber(idcardnumber), position("") {
    salary = new double;
    *salary = 0.0;
    cout << "Викликано конструктор для Employee з 2 параметрами" << endl;
}

Employee::Employee(string fullName, int idcardnumber, double salaryValue) 
    : fullName(fullName), idcardnumber(idcardnumber), position("") {
    salary = new double;
    *salary = salaryValue;
    cout << "Викликано конструктор для Employee з 3 параметрами" << endl;
}

Employee::Employee(string fullName, int idcardnumber, double salaryValue, string position) 
    : fullName(fullName), idcardnumber(idcardnumber), position(position) {
    salary = new double;
    *salary = salaryValue;
    cout << "Викликано конструктор для Employee з 4 параметрами" << endl;
}

Employee::Employee(const Employee &other) 
    : fullName(other.fullName), idcardnumber(other.idcardnumber), position(other.position) {
    salary = new double;
    *salary = *(other.salary);
    cout << "Викликано конструктор копіювання для Employee" << endl;
}


Employee::Employee(Employee&& other) noexcept
    : fullName(std::move(other.fullName)), 
    idcardnumber(other.idcardnumber), 
    position(std::move(other.position)) {
    
    salary = other.salary; // "Крадемо" вказівник
    
    // Обнуляємо дані у тимчасовому об'єкті
    other.salary = nullptr;
    other.idcardnumber = 0;

    cout << "Викликано конструктор переміщення для Employee: " << fullName << endl;
}

Employee::~Employee() {
    delete salary;
    cout << "Спрацював деструктор класу Employee" << endl;
}

void Employee::promote(string newPosition) {
    position = newPosition;
}

void Employee::updateSalary(double bonus) {
    *salary += bonus;
}


void Employee::showProfile() {
    cout << "Співробітник: " << fullName << ", Посада: " << position << endl;
}

double Employee::getSalary() {
    return *salary;
}