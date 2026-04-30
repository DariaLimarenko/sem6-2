#include "Person.h"
using namespace std;

Person::Person(string n, int a) : name(n), age(a) {}

string Person::getName() const {
    return name;
}
