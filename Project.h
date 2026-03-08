#pragma once

#include <iostream>
#include <string>
#include "Employee.h"

class Project {
private:
    std::string title;
    double budget;
    int durationweeks;
    bool isActive;

public:
    Project(std::string nazva = "Hacking", double koshty = 10000, int duration = 12, bool status = true);
    Project(std::string zagolovok, double moneycount);
    Project(const Project& other);
    ~Project();

    void changeFinanciaton(double change);
    void profit();
    void getStatusOfProject();
    void assignManager(Employee manager);
};