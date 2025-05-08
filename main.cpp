#include <iostream>
#include <string>
#include "Bus.h"
#include "User.h"
#include "Ticket.h"
#include "Student.h"
using namespace std;

void menu(Bus& bus, Ticket tickets[], int& ticketCount, string username, int& nextTicketID) {
    Student student(username);
    string time, departure, arrival;
    int num;
   // student.displayMenu();
    // cout<<"Enter Numbers of ticket you want to buy:";
    // cin>>num;
    // for(int i=0;i<num;i++){
    //     cout << "\nEnter Departure Location (Rawalpindi / Islamabad / Peshawar / Abbottabad / GIKI Institute): ";
    //     cin.ignore();
    //     getline(cin, departure);
    //     cout << "Enter Arrival Location Rawalpindi / Islamabad / Peshawar / Abbottabad / GIKI Institute): ";
    //     getline(cin, arrival);

    //     if (departure == "GIKI Institute" || arrival == "GIKI Institute") {
    //         break;
    //     } else {
    //         cout << "One location must be GIKI Institute!\n";
    //     }
    // }

    while (true) {
        student.displayMenu();
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 4) break;

        cout << "Select Time (1 PM / 6 PM): ";
        cin.ignore();
        getline(cin, time);

        switch (choice) {
            case 1:
                bus.displaySeatsWithNumbers(time);
                break;
            case 2: {
                int seat;
                int num;
                cout<<"Enter the number of tickets you want to Purchase: ";
                cin>>num;
                cin.ignore();

                
                for(int i=1;i<=num;i++){ 
                    cout<<"For your Ticket "<<i<<endl;
                    cout << "Select Departure Location (Rawalpindi / Islamabad / Peshawar / Abbottabad / GIKI ): ";
                    getline(cin, departure);
                    cout << "Select Arrival Location Rawalpindi / Islamabad / Peshawar / Abbottabad / GIKI ): ";
                    getline(cin, arrival);
                    //cout << "DEBUG: Departure = [" << departure << "], Arrival = [" << arrival << "]\n";
                if(!(departure == "GIKI" || arrival == "GIKI")) {
                    cout << "One location must be GIKI Institute!\n";
                    i--;
                    continue;   
                }
                cout << "Enter Seat Number (1-40): ";
                cin >> seat;
                cin.ignore();
                if (bus.bookSeat(seat, time)) {
                    tickets[ticketCount++] = {nextTicketID++, username, seat, time, true,departure,arrival};
                    cout << "Ticket booked successfully!\n";
                    saveTicketsToFile(tickets, ticketCount);
                } else {
                    cout << "Seat already booked or invalid.\n";
                    i--;
                }
            }
                break;
            
            }
            case 3: {
                int seat;
                cout << "Enter Seat Number to Cancel: ";
                cin >> seat;
                for (int i = 0; i < ticketCount; i++) {
                    if (tickets[i].studentID == username && tickets[i].seatNumber == seat && tickets[i].time == time && tickets[i].paymentConfirmed) {
                        bus.cancelSeat(seat, time);
                        tickets[i].paymentConfirmed = false;
                        cout << "Ticket cancelled.\n";
                        saveTicketsToFile(tickets, ticketCount);
                        break;
                    }
                }
                break;
            }
            default:
                cout << " Invalid choice!\n";
        }
    }
}

int main() {
    Bus collegeBus;
    Ticket tickets[100];
    int ticketCount = 0;
    int nextTicketID = 1000;
    string loggedInUser;

    while (true) {
        cout << "\n================ Welcome ================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        int opt;
        cin >> opt;

        if (opt == 1) registerUser();
        else if (opt == 2) {                        //note: use switch
            if (loginUser(loggedInUser)) {
                menu(collegeBus, tickets, ticketCount, loggedInUser, nextTicketID);
            }
        }
        else break;
    }

    return 0;
}
//g++ src/main.cpp src/Bus.cpp src/User.cpp src/Ticket.cpp -I include -o TicketingSystem
//./TicketingSystem
