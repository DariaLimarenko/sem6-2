#ifndef DIARY_H
#define DIARY_H

#include <vector>
using namespace std;

class Diary {
private:
    vector<int> grades;

public:
    void addGrade(int grade);
    double calculateAverage() const;
    void showGrades() const;
};

#endif
