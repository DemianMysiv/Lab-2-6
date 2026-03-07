#pragma once

#include <iostream>
#include <string>

class Project {
private:
    std::string title;
    double budget;
    int durationweeks;
    bool isActive;

public:
    Project(std::string nazva = "Hacking", double koshty = 10000, int duration = 12, bool status = true);
    Project(std::string zagolovok, double moneycount);
    ~Project();

    void changeFinanciaton(double change);
    void profit();
    void getStatusOfProject();
};