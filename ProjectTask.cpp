#include "ProjectTask.h"

ProjectTask::ProjectTask(std::string t, int h) : title(t), baseHours(h) {}

ProjectTask::~ProjectTask() {}

std::string ProjectTask::getTitle() const {
    return title;
}

int ProjectTask::getBaseHours() const {
    return baseHours;
}