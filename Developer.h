#include "Employee.h"
#include <string>

class Developer final : public Employee {
private:
    std::string programmingLanguage;
    std::string githubProfile;

public:
    Developer(std::string fullName, int idcardnumber, double salaryvalue, std::string position, std::string language, std::string github);
    ~Developer();
    void writeCode() const;
    void debugCode() const;
    void sendCommit() const;
    double calculateAnnualBonus() const override;

};
