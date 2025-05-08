#ifndef USER_H
#define USER_H


 void registerUser();
 bool loginUser(string &loggedInUser);

 #include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin.ignore();
    getline(cin,username);
    
    cout << "Enter password: ";
    getline(cin,password);
    
    ofstream file("users.txt");
    file << username << "," << password << endl;
    file.close();

    cout << "User registered successfully!\n";
}

bool loginUser(string &loggedInUser) {
    string username, password;
    cout << "Username: ";
    cin.ignore();
    getline(cin,username);
    cout << "Password: ";
    getline(cin,password);
    

    

    ifstream file("users.txt");
    string line;
    while (getline(file,line)) {
        size_t commaPos=line.find(','); //finding comma using find function  // comma will appear in file(txt) one user is registered.
        string u=line.substr(0,commaPos);    //making substring using substr function which reads name before commaPos.
        string p=line.substr(commaPos+1);// it will read password which is after commaPos in file.
        if (u == username && p == password) {
            loggedInUser = username;
            cout << " Login successful!\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}
#endif