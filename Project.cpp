#include "Project.h"

using namespace std;

int Project::totalProjects = 0;

Project::Project() : title{"Hacking"}, budget{10000}, durationweeks{12}, isActive{true} {
    totalProjects++;
    cout << "Викликався конструктор за замовчуванням" << endl;
}

Project::Project(string nazva, double koshty, int duration, bool status) 
    : title{ nazva }, budget{ koshty }, durationweeks{ duration }, isActive{ status } {
    totalProjects++;
    cout << "Викликано конструктор з 4 параметрами" << endl;
}

Project::Project(string zagolovok, int d) 
    : title{ zagolovok }, budget{ 1000 }, durationweeks{ d }, isActive{ true } {
    totalProjects++;
    cout << "Викликано конструктор з 2 параметрами" << endl;
}

Project::Project(const Project& other) 
    : title(other.title), budget(other.budget), 
      durationweeks(other.durationweeks), isActive(other.isActive) {
    totalProjects++;
    cout << "Викликано конструктор копіювання для проєкту: " << title << endl;
}

Project::~Project() {
    totalProjects--;
    cout << "Спрацював деструктор для проєкту: " << title << endl;
}

int Project::getTotalProjects() {
    return totalProjects;
}

void Project::changeFinanciaton(double change) {
    budget += change;
}

void Project::profit() {
    cout << "Проєкт " << title << " успішно приносить прибуток компанії." << endl;
}

void Project::getStatusOfProject() {
    cout << "Статус проєкту " << title << " | Бюджет: " << budget << " | Тижнів: " << durationweeks << endl;
}

void Project::assignManager(Employee manager) {
    cout << "\n*** Призначення на проєкт: " << title << " ***" << endl;
    cout << "Керівник проєкту:" << endl;
    manager.showneededinfo(); // Клас Project викликає метод класу Employee!
    cout << "**************************************\n" << endl;
}

// Stream insertion operator (<<)
std::ostream &operator<<(std::ostream &os, const Project &obj) {
    // Виводимо дані проєкту у потік.
    os << "Проєкт: " << obj.title 
       << " | Бюджет: " << obj.budget 
       << " | Тривалість: " << obj.durationweeks 
       << " | Статус: " << obj.isActive << std::endl;
    return os;
}

// Stream extraction operator (>>)
std::istream &operator>>(std::istream &is, Project &obj) {
    // 1. Виділяємо буфер, як у лекційному прикладі
    char *buff = new char[1000];
    double tempBudget;
    int tempDuration;
    bool tempStatus;

    cout << "Введіть назву, бюджет, тижні та статус (1/0) через пробіл: ";
    
    // 2. Зчитуємо дані з консолі
    is >> buff >> tempBudget >> tempDuration >> tempStatus;
    
    // 3. Створюємо новий об'єкт і присвоюємо його поточному.
    obj = Project{buff, tempBudget, tempDuration, tempStatus};
    
    // 4. Обов'язково очищаємо динамічну пам'ять!
    delete[] buff;
    
    // 5. Повертаємо потік
    return is;
}


void Project::display() const {
        std::cout << "[Проєкт]: " << title << std::endl;
    }

std::string Project::toFileString() const {
    return "Project " + title + " " + std::to_string(durationweeks);
}


