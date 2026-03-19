#include "Employee.h"
#include <string>

class Developer : public Employee {
private:
    std::string programmingLanguage;
    std::string githubProfile;

public:

    void writeCode() const;
    void debugCode() const;
    void sendCommit() const;

};
