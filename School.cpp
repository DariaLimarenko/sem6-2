#include <iostream>
#include "School.h"
using namespace std;

School::School(string name) : schoolName(name) {}

void School::addStudent(Student* student) {
    students.push_back(student);
}

void School::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}

void School::showAllStudents() const {
    cout << "\n--- Список учеников школы " << schoolName << " ---" << endl;
    for (Student* student : students) {
        student->showInfo();
    }
}

void School::showAllTeachers() const {
    cout << "\n--- Список учителей школы " << schoolName << " ---" << endl;
    for (Teacher* teacher : teachers) {
        teacher->showInfo();
    }
}

void School::showExcellentStudents() const {
    cout << "\n--- Ученики со средним баллом >= 4 ---" << endl;
    for (Student* student : students) {
        if (student->getAverageGrade() >= 4.0) {
            student->showInfo();
        }
    }
}
