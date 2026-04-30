#include <iostream>
#include "Diary.h"
using namespace std;

void Diary::addGrade(int grade) {
    if (grade >= 2 && grade <= 5) {
        grades.push_back(grade);
    } else {
        cout << "Оценка должна быть от 2 до 5!" << endl;
    }
}

double Diary::calculateAverage() const {
    if (grades.empty()) {
        return 0.0;
    }

    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}

void Diary::showGrades() const {
    if (grades.empty()) {
        cout << "Оценок пока нет.";
        return;
    }

    cout << "Оценки: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
}
