#pragma once

#include <string>

class ProjectTask {
protected:
    std::string title;
    int baseHours;

public:
    ProjectTask(std::string t, int h);
    virtual ~ProjectTask();

    virtual double calculatePriority() const = 0;

    std::string getTitle() const;
    int getBaseHours() const;
};