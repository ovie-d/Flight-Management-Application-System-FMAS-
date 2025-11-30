#include "Passenger.h"
#include <iostream>
using namespace std;
#include <string>

// constructor
Passenger::Passenger() : Firstname(), Lastname(), row(), seat(), ID(), PhoneNumber() {}

Passenger::Passenger(string firstname, string lastname, int row, char seat, int ID, string PhoneNumber)
    : Firstname(firstname), Lastname(lastname), row(row), seat(seat), ID(ID), PhoneNumber(PhoneNumber) {

    if (Firstname.empty()) {
        cout << "Error: First name cannot be empty." << endl;
    }

    if (Lastname.empty()) {
        cout << "Error: Last name cannot be empty." << endl;
    }

    if (PhoneNumber.empty()) {
        cout << "Error: Phone number cannot be empty." << endl;
    }

    if (ID <= 0000 || ID > 9999) {
        cout << "Error: ID must be a positive number." << endl;
    }

    }

 // setters
void Passenger::changePassengerDetails(string firstname, string lastname, string PhoneNumber) {
    Firstname = firstname;
    Lastname = lastname;
    this->PhoneNumber = PhoneNumber;
}

void Passenger::changePassengerFirstname(string firstname) {
    if (firstname.empty()) {
        cout << "Error: First name cannot be empty." << endl;
        return;
    }

    Firstname = firstname;
}

void Passenger::changePassengerLastname(string lastname) {
    if (lastname.empty()) {
        cout << "Error: Last name cannot be empty." << endl;
        return;
    }

    Lastname = lastname;
}

void Passenger::changePassengerPhoneNumber(string PhoneNumber) {
    this->PhoneNumber = PhoneNumber;
}

// destructor
Passenger::~Passenger() {}

// getters 
string Passenger::get_Firstname() const {
    return Firstname;
}

string Passenger::get_Lastname() const {
    return Lastname;
}

string Passenger::get_fullname() const {
    return Firstname + " " + Lastname;
}
char Passenger::get_seat() const {
    return seat;
}

int Passenger::get_row() const {
    return row;
}

string Passenger::get_seatandrow() const {
    return to_string(row) + seat;
}

int Passenger::get_ID() const {
    return ID;
}

string Passenger::get_PhoneNumber() const {
    return PhoneNumber;
}