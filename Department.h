#pragma once

#include <iostream>
#include <string>

class Department {
private:
    std::string deptName;
    int employeecount;
    int floor;
    std::string resources;

public:
    Department();
    Department(std::string name, int count);
    Department(std::string name, int count, int fl);
    Department(std::string name, int count, int fl, std::string res);
    ~Department();

    void relocate(int newfloor);
    void hireEmployee(int addedcount);
    void setResources(std::string newResources);
};