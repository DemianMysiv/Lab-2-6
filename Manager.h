#include "Employee.h"
#include <string>

class Manager : public Employee {
private:
    int teamSize;
    std::string department;

public:

    void addTeamMember();
    void conductMeeting() const;
};