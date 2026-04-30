#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>
#include <string>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class School {
private:
    string schoolName;
    vector<Student*> students;
    vector<Teacher*> teachers;

public:
    School(string name);

    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);

    void showAllStudents() const;
    void showAllTeachers() const;
    void showExcellentStudents() const;
};

#endif
