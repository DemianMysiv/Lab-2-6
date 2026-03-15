#pragma once

#include <iostream>
#include <string>

class Department {
private:
    char* deptName;
    int employeecount;
    int floor;
    std::string resources;

public:
    Department();
    Department(const char* name, int count);
    Department(const char* name, int count, int fl);
    Department(const char* name, int count, int fl, std::string res);
    Department(const Department& other); 
    ~Department();

    Department operator-() const;
    Department operator+(const Department& rhs) const;

    void relocate(int newfloor);
    void hireEmployee(int addedcount);
    void setResources(std::string newResources);
    void display() const;
};