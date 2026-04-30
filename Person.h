#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a);

    virtual void showInfo() const = 0;
    virtual string getRole() const = 0;

    string getName() const;
    virtual ~Person() = default;
};

#endif
