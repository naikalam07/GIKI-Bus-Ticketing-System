#ifndef BUS_H
#define BUS_H
#include <iostream>
#include <string>
using namespace std;

const int NUM_SEATS = 40;
const int NUM_TIMESLOTS = 2;
const string TIME_SLOTS[NUM_TIMESLOTS] = {"1 PM", "6 PM"};

class Bus {
private:
    bool seats[NUM_TIMESLOTS][NUM_SEATS];
public:
    Bus();
    int getTimeIndex(string time);
    bool isSeatAvailable(int seatNumber, string time);
    bool bookSeat(int seatNumber, string time);
    void cancelSeat(int seatNumber, string time);
    void displaySeatsWithNumbers(string time);
};


Bus::Bus() {
    for (int t = 0; t < NUM_TIMESLOTS; t++)
        for (int s = 0; s < NUM_SEATS; s++)
            seats[t][s] = false;
}

int Bus::getTimeIndex(string time) {
    for (int i = 0; i < NUM_TIMESLOTS; i++) {
        if (TIME_SLOTS[i] == time)
            return i;
    }
    return -1;
}

// bool Bus::isSeatAvailable(int seatNumber, string time) {
//     int t = getTimeIndex(time);
//     return t != -1 && seatNumber >= 1 && seatNumber <= NUM_SEATS && !seats[t][seatNumber - 1];
// }

// bool Bus::bookSeat(int seatNumber, string time) {
//     int t = getTimeIndex(time);
//     if (isSeatAvailable(seatNumber, time)) {
//         seats[t][seatNumber - 1] = true;
//         return true;
//     }
//     return false;
// }
bool Bus::bookSeat(int seatNumber, string time) {
    int t = getTimeIndex(time);
    if (t != -1 && seatNumber >= 1 && seatNumber <= NUM_SEATS) {
        if (!seats[t][seatNumber - 1]) {   // Seat is free
            seats[t][seatNumber - 1] = true; //  Mark it as booked
            return true;
        }
    }
    return false;  //  Seat was already booked or invalid
}


void Bus::cancelSeat(int seatNumber, string time) {
    int t = getTimeIndex(time);
    if (t != -1 && seatNumber >= 1 && seatNumber <= NUM_SEATS)
        seats[t][seatNumber - 1] = false;
}

void Bus::displaySeatsWithNumbers(string time) {
    int t = getTimeIndex(time);
    cout << "Seat layout at " << time << ":\n";
    for (int i = 0; i < NUM_SEATS; i++) {
        if (seats[t][i])
            cout << "[X]";
        else
            cout << "[" << i + 1 << "]";
        if ((i + 1) % 4 == 0) cout << "\t \t";
        if ((i + 1) % 8 == 0) cout << endl;
    }
    cout << endl;
}
#endif
