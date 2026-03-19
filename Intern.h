#include "Employee.h"
#include <string>

class Intern : public Employee {
private:
    std::string university;
    std::string mentorname;
    int internshipDuration;

public:
 std::string getplaceofeducation();
 std::string getmentorname();
 int getmounthsofDuration();

};