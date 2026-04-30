#include <iostream>
#include "Student.h"
#include "Teacher.h"
using namespace std;

Student::Student()
    : Person("", 0), studentId(0), classTeacher(nullptr) {}

Student::Student(string n, int a, int id)
    : Person(n, a), studentId(id), classTeacher(nullptr) {}

void Student::setClassTeacher(Teacher* teacher) {
    classTeacher = teacher;
}

void Student::addGrade(int grade) {
    diary.addGrade(grade);
}

double Student::getAverageGrade() const {
    return diary.calculateAverage();
}

int Student::getStudentId() const {
    return studentId;
}

void Student::showDiary() const {
    cout << "Дневник ученика " << name << ": ";
    diary.showGrades();
    cout << ", средний балл = " << getAverageGrade() << endl;
}

void Student::showInfo() const {
    cout << "Ученик: " << name
         << ", возраст: " << age
         << ", ID: " << studentId;

    if (classTeacher != nullptr) {
        cout << ", классный руководитель: " << classTeacher->getName();
    } else {
        cout << ", классный руководитель не назначен";
    }

    cout << endl;
}

string Student::getRole() const {
    return "Ученик";
}

bool Student::operator==(const Student& other) const {
    return studentId == other.studentId;
}

bool Student::operator<(const Student& other) const {
    return studentId < other.studentId;
}
