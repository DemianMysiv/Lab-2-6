#pragma once

#include "ProjectTask.h"

class CodingTask : public ProjectTask {
private:
    int difficultyLevel;

public:
    CodingTask(std::string t, int h, int diff);
    double calculatePriority() const override;
};