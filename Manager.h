#include "Employee.h"
#include <string>

class Manager : public Employee {
private:
    int teamSize;
    std::string department;

public:
    Manager(std::string Name, int id, double salary, int team, std::string dept, std::string position);
    ~Manager();
    void addTeamMember();
    void conductMeeting() const;
    void showneededinfo() const;
    double calculateAnnualBonus() const;
};