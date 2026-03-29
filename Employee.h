#pragma once

#include <string>
#include <iostream>

class Employee {
private:
    std::string fullName;
    int idcardnumber;
    double *salary;
    std::string position;

public:
    Employee();
    Employee(std::string fullName);
    Employee(std::string fullName, int idcardnumber);
    Employee(std::string fullName, int idcardnumber, double salaryvalue);
    Employee(std::string fullName, int idcardnumber, double salaryvalue, std::string position);
    Employee(const Employee &other);
    Employee(Employee&& other) noexcept;
    ~Employee();

    void promote(std::string newPosition);
    void updateSalary(double bonus);
    void showneededinfo() const;
    double getSalary() const;
    int WhoisthisP(const Employee &other);
    

};