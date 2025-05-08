#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
using namespace std;

class Student : public Person {
public:
    Student(string uname) : Person(uname) {}

    void displayMenu() override {
        cout << "\n===========================================\n";
        cout << " Welcome " << username << " to College Bus Ticketing System\n";
        cout << "===========================================\n";
        cout << "1. View Seats\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Exit to Main Menu\n";
    }
};

#endif
