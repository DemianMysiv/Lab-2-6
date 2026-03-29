#include "CodingTask.h"

CodingTask::CodingTask(std::string t, int h, int diff) 
    : ProjectTask(t, h), difficultyLevel(diff) {}

double CodingTask::calculatePriority() const {
    return baseHours * difficultyLevel * 1.5;
}