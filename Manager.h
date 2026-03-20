#include "Employee.h"
#include <string>

class Manager : public Employee {
private:
    int teamSize;
    std::string department;

public:
    Manager(std::string id, double salary, int team, std::string dept);
    ~Manager();
    void addTeamMember();
    void conductMeeting() const;
};