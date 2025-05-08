#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string username;
public:
    Person(string uname) : username(uname) {}
    virtual void displayMenu() = 0; // Abstract method
};

#endif
