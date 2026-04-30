#include <iostream>
#include "Teacher.h"
using namespace std;

Teacher::Teacher(string n, int a, string sub)
    : Person(n, a), subject(sub) {}

string Teacher::getSubject() const {
    return subject;
}

void Teacher::showInfo() const {
    cout << "Учитель: " << name
         << ", возраст: " << age
         << ", предмет: " << subject << endl;
}

string Teacher::getRole() const {
    return "Учитель";
}
