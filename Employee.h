#pragma once

#include <string>
#include <iostream>

class Employee {
private:
    std::string fullName;
    int idcardnumber;
    double salary;
    std::string position;

public:
    Employee();
    Employee(std::string fullName);
    Employee(std::string fullName, int idcardnumber);
    Employee(std::string fullName, int idcardnumber, double salary);
    Employee(std::string fullName, int idcardnumber, double salary, std::string position);
    ~Employee();

    void promote(std::string newPosition);
    void updateSalary(double bonus);
    void showProfile();
    
};