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
    static int totalProjects;

public:
    Project();
    Project(std::string nazva, double koshty, int duration, bool status);
    Project(std::string zagolovok, double moneycount);
    Project(const Project& other);
    ~Project();

    void changeFinanciaton(double change);
    void profit();
    void getStatusOfProject();
    void assignManager(Employee manager);
    static int getTotalProjects();
};