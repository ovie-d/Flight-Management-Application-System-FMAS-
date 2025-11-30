#include "Flight.h"
#include "Passenger.h"
#include <iostream>

#include <string>

//constuctor 
Flight::Flight() : flightNumber(), departureCity(), arrivalCity(), number_of_rows(0), number_of_seats_per_row(0) {}
Flight::Flight(std::string flightNumber, std::string departureCity, std::string arrivalCity, int number_of_rows, int number_of_seats_per_row)
    : flightNumber(flightNumber), departureCity(departureCity), arrivalCity(arrivalCity),
      number_of_rows(number_of_rows), number_of_seats_per_row(number_of_seats_per_row) {

    if (flightNumber.empty()) {
        std::cout << "Error: Flight number cannot be empty." << std::endl;
    }

    if (departureCity.empty()) {
        std::cout << "Error: Departure city cannot be empty." << std::endl;
    }

    if (arrivalCity.empty()) {
        std::cout << "Error: Arrival city cannot be empty." << std::endl; 
    }

    if (number_of_rows <= 0) {
        std::cout << "Error: Number of rows must be a positive integer." << std::endl;
    }

    if (number_of_seats_per_row <= 0) {
        std::cout << "Error: Number of seats per row must be a positive integer." << std::endl;
    }

    if (number_of_seats_per_row > 24) {
        std::cout << "Error: Number of seats per row cannot exceed 24." << std::endl;
    }
    if (number_of_rows > 6) {
        std::cout << "Error: Number of rows cannot exceed 6." << std::endl;
    }
}

// getters
std::string Flight::get_flightNumber() const {
    return flightNumber;
}

std::string Flight::get_departureCity() const {
    return departureCity;
}

std::string Flight::get_arrivalCity() const {
    return arrivalCity;
}

std::vector<Passenger> Flight::get_passengers() const {
    return passengers;
}

int Flight::get_number_of_rows() const {
    return number_of_rows;
}

int Flight::get_number_of_seats_per_row() const {
    return number_of_seats_per_row;
}

// destructor
Flight::~Flight() {}

bool Flight::is_seat_taken(int row, char seat) const {
    for (size_t i = 0; i < passengers.size(); ++i) {
        const Passenger& passenger = passengers[i];
        if (passenger.get_row() == row && passenger.get_seat() == seat) {
            return true;
        }
    }
    return false;
}

bool Flight::remove_passenger(int ID) {
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers[i].get_ID() == ID) {
            passengers.erase(passengers.begin() + i);
            return true;
        }
    }
    return false;  
}

bool Flight::add_passenger(const Passenger& passenger) {
    int row = passenger.get_row();
    char seat = passenger.get_seat();
    int ID = passenger.get_ID();

    // Row range check
    if (row < 0 || row >= number_of_rows) {
        std::cout << "Invalid row number.\n";
        return false;
    }

    // Seat range check
    char maxSeat = 'A' + number_of_seats_per_row - 1;
    if (seat < 'A' || seat > maxSeat) {
        std::cout << "Invalid seat letter.\n";
        return false;
    }

    // Seat taken check
    if (is_seat_taken(row, seat)) {
        std::cout << "Seat already taken.\n";
        return false;
    }

    // Duplicate ID check
    for (size_t i = 0; i < passengers.size(); ++i) {
        const Passenger& p = passengers[i];
        if (p.get_ID() == ID) {
            std::cout << "Passenger ID already exists.\n";
            return false;
        }
    }
    // If all checks pass, add the passenger
    std::cout << "Passenger added successfully.\n";
    std::cout << "Passenger ID: " << ID << ", Row: " << row << ", Seat: " << seat << "\n";
    std::cout << "Passenger Name: " << passenger.get_fullname() << "\n";
    std::cout << "Passenger Phone Number: " << passenger.get_PhoneNumber() << "\n";
    passengers.push_back(passenger);
    return true;
}