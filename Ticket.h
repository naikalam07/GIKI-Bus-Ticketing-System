
#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <fstream>
using namespace std;

struct Ticket {
    int ticketID;
    string studentID;
    int seatNumber;
    string time;
    bool paymentConfirmed;
    string departure;
    string arrival;
    
};



void saveTicketsToFile(Ticket tickets[], int ticketCount) {
    ofstream file("tickets.txt");
    for (int i = 0; i < ticketCount; i++) {
        
        if (tickets[i].paymentConfirmed) {
            file << "Ticket ID: " << tickets[i].ticketID
                 << ", Student Name: " << tickets[i].studentID
                 << ", Seat: " << tickets[i].seatNumber
                 << ", Time: " << tickets[i].time
                 << ", From: " << tickets[i].departure
                 << ", To: " << tickets[i].arrival << endl;
        }
    }
    file.close();
}
#endif
