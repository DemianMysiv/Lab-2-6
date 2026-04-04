#pragma once
#include <string>
#include <iostream>
#include "IDisplayable.h"

class Employee : public IDisplayable {
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

    virtual ~Employee();

    void promote(std::string newPosition);
    void updateSalary(double bonus);
    void showneededinfo();

    virtual double calculateAnnualBonus() const;

    double getSalary() const;
    int WhoisthisP(const Employee &other);
    void display() const override;
    

};