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

Project::Project(string zagolovok, double moneycount) 
    : title{ zagolovok }, budget{ moneycount }, durationweeks{ 5 }, isActive{ true } {
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
    manager.showProfile(); // Клас Project викликає метод класу Employee!
    cout << "**************************************\n" << endl;
}