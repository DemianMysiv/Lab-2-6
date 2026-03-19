#include "Department.h"
#include "Manager.h"
#include <cstring>
#include <cctype>

using namespace std;

Department::Department() : Department("Marketing", 0, 1, "Standard") {}

Department::Department(const char* name, int count) : Department(name, count, 1, "Standard") {}

Department::Department(const char* name, int count, int fl) : Department(name, count, fl, "Standard") {}

Department::Department(const char* name, int count, int fl, string res) 
    : employeecount{ count }, floor{ fl }, resources{ res }, departmentHead{ nullptr } {
    deptName = new char[std::strlen(name) + 1];
    std::strcpy(deptName, name);
}

Department::Department(const Department& other) 
    : employeecount{ other.employeecount }, floor{ other.floor }, resources{ other.resources }, departmentHead{ other.departmentHead } {
    deptName = new char[std::strlen(other.deptName) + 1];
    std::strcpy(deptName, other.deptName);
}

Department::~Department() {
    delete[] deptName;
}

Department Department::operator-() const {
    char *buff = new char[std::strlen(this->deptName) + 1];
    std::strcpy(buff, this->deptName);
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Department temp{buff, this->employeecount, this->floor, this->resources};
    delete[] buff;
    return temp;
}

Department Department::operator+(const Department &rhs) const {
    size_t buffSize = std::strlen(this->deptName) + std::strlen(rhs.deptName) + 1;
    char *buff = new char[buffSize];
    std::strcpy(buff, this->deptName);
    std::strcat(buff, rhs.deptName);
    Department temp{buff, this->employeecount + rhs.employeecount, this->floor, this->resources};
    delete[] buff;
    return temp;
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

void Department::display() const {
    cout << "Відділ: " << deptName << " | Працівників: " << employeecount 
         << " | Поверх: " << floor << " | Ресурси: " << resources;
    
    if (departmentHead != nullptr) {
        cout << " | [Керівник призначений]";
    } else {
        cout << " | [Без керівника]";
    }
    cout << endl;
}




void Department::assignManager(Manager* newManager) {
    departmentHead = newManager;
    cout << "Відділу '" << deptName << "' успішно призначено нового керівника." << endl;
}

void Department::showDepartmentHead() const {
    if (departmentHead != nullptr) {
        cout << "Керівник відділу '" << deptName << "' на місці." << endl;
    } else {
        cout << "У відділі '" << deptName << "' наразі немає керівника!" << endl;
    }
}