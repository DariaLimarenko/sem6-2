#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string n, int a, string sub);
    string getSubject() const;
    void showInfo() const override;
    string getRole() const override;
};

#endif
