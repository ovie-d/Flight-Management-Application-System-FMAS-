#include "Flight.h"
#include "Passenger.h"
#include <iostream>

#include <string>
#include "SeatMap.h" // Needed for print_seat_map implementation

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

    // Note: The SeatMap array size is [24][6], so the maximum rows is 24 and max seats per row is 6.
    // The checks below are based on the project's implicit constraints.
    if (number_of_rows > 24) {
        std::cout << "Error: Number of rows cannot exceed 24." << std::endl;
    }
    if (number_of_seats_per_row > 6) {
        std::cout << "Error: Number of seats per row cannot exceed 6." << std::endl;
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

// display helpers
void Flight::print_passenger_list() const {
    std::cout << "\n--- Passenger List for Flight " << flightNumber << " ---\n";
    if (passengers.empty()) {
        std::cout << "No passengers currently booked on this flight.\n";
        return;
    }
    
    // Print header
    std::cout << "ID\tSeat\tName\t\tPhone\n";
    std::cout << "--------------------------------------------------\n";

    for (const auto& p : passengers) {
        std::cout << p.get_ID() << "\t"
                  << p.get_seatandrow() << "\t"
                  << p.get_fullname() << "\t"
                  << p.get_PhoneNumber() << "\n";
    }
    std::cout << "--------------------------------------------------\n";
}

void Flight::print_seat_map() const {
    // This function should not be called directly by main.cpp, but it's defined here for completeness.
    // The main logic for displaying the map is in SeatMap.cpp.
    // The main.cpp is calling displaySeatMap directly, so we will update main.cpp later.
    // For now, we will implement the logic to generate the map data.
    
    // Create a 2D array to represent the seat map (24 rows x 6 seats)
    int seatMap[24][6] = {0}; // Initialize all to 0 (available)
    
    // Mark occupied seats
    for (const auto& p : passengers) {
        int row = p.get_row();
        char seat = p.get_seat();
        
        // Convert row (1-indexed) to array index (0-indexed)
        int row_index = row - 1;
        // Convert seat (A=0, B=1, ...) to array index
        int col_index = seat - 'A';
        
        // Check bounds before marking (safety check)
        if (row_index >= 0 && row_index < number_of_rows && 
            col_index >= 0 && col_index < number_of_seats_per_row) {
            
            seatMap[row_index][col_index] = 1; // 1 means occupied
        }
    }
    
    // Since print_seat_map is a member of Flight, it should call the external display function.
    // We need to include SeatMap.h here.
    // Note: The main.cpp is currently calling displaySeatMap directly. We will fix main.cpp later.
    // For now, we assume displaySeatMap is available.
    
    // We need to include SeatMap.h at the top of Flight.cpp
    // The actual display logic is in SeatMap.cpp (Alex's part)
    // The actual display logic is in SeatMap.cpp (Alex's part)
    // Call the external display function with the generated map data
    displaySeatMap(flightNumber, seatMap);
}

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