#include "Passenger.h"
#include <iostream>

#include <string>

// constructor
Passenger::Passenger() : Firstname(), Lastname(), row(), seat(), ID(), PhoneNumber() {}

Passenger::Passenger(std::string firstname, std::string lastname, int row, char seat, int ID, std::string PhoneNumber)
    : Firstname(firstname), Lastname(lastname), row(row), seat(seat), ID(ID), PhoneNumber(PhoneNumber) {

    if (Firstname.empty()) {
        std::cout << "Error: First name cannot be empty." << std::endl;
    }

    if (Lastname.empty()) {
        std::cout << "Error: Last name cannot be empty." << std::endl;
    }

    if (PhoneNumber.empty()) {
        std::cout << "Error: Phone number cannot be empty." << std::endl;
    }

    if (ID <= 0000 || ID > 9999) {
        std::cout << "Error: ID must be a positive number." << std::endl;
    }

    }

 // setters
void Passenger::changePassengerDetails(std::string firstname, std::string lastname, std::string PhoneNumber) {
    Firstname = firstname;
    Lastname = lastname;
    this->PhoneNumber = PhoneNumber;
}

void Passenger::changePassengerFirstname(std::string firstname) {
    if (firstname.empty()) {
        std::cout << "Error: First name cannot be empty." << std::endl;
        return;
    }

    Firstname = firstname;
}

void Passenger::changePassengerLastname(std::string lastname) {
    if (lastname.empty()) {
        std::cout << "Error: Last name cannot be empty." << std::endl;
        return;
    }

    Lastname = lastname;
}

void Passenger::changePassengerPhoneNumber(std::string PhoneNumber) {
    this->PhoneNumber = PhoneNumber;
}

// destructor
Passenger::~Passenger() {}

// getters 
std::string Passenger::get_Firstname() const {
    return Firstname;
}

std::string Passenger::get_Lastname() const {
    return Lastname;
}

std::string Passenger::get_fullname() const {
    return Firstname + " " + Lastname;
}
char Passenger::get_seat() const {
    return seat;
}

int Passenger::get_row() const {
    return row;
}

std::string Passenger::get_seatandrow() const {
    std::stringstream ss;
    ss << row << seat;
    return ss.str();
}

int Passenger::get_ID() const {
    return ID;
}

std::string Passenger::get_PhoneNumber() const {
    return PhoneNumber;
}