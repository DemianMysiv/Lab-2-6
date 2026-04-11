#pragma once

#include <iostream>
#include <string>
#include "Employee.h"

class Project : public IDisplayable{
private:
    std::string title;
    double budget;
    int durationweeks;
    bool isActive;
    static int totalProjects;

public:
    Project();
    Project(std::string nazva, double koshty, int duration, bool status);
    Project(std::string zagolovok, int d);
    Project(const Project& other);
    ~Project();
    friend std::ostream &operator<<(std::ostream &os, const Project &obj);
    friend std::istream &operator>>(std::istream &is, Project &obj);


    void display() const override;

    void changeFinanciaton(double change);
    void profit();
    void getStatusOfProject();
    void assignManager(Employee manager);
    static int getTotalProjects();

    std::string toFileString() const override;
};