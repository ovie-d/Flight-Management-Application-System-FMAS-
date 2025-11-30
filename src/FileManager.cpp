#include "../include/FileManager.h"
#include "../include/Flight.h"
#include "../include/Passenger.h"
#include <sstream>
#include <iostream>

// Helper function to find a flight by ID
Flight* findFlightById(std::vector<Flight>& flights, const std::string& flightId) {
    for (auto& flight : flights) {
        if (flight.id == flightId) {
            return &flight;
        }
    }
    return nullptr;
}

// Function to load flight data from flights.txt
bool FileManager::loadFlights(std::vector<Flight>& flights) {
    std::ifstream file("data/flights.txt");
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, departure, destination;
        int rows, seatsPerRow;

        // Use C++ streams for parsing, as taught in C++ File I/O lecture
        if (ss >> id >> departure >> destination >> rows >> seatsPerRow) {
            Flight newFlight(id, departure, destination, rows, seatsPerRow);
            flights.push_back(newFlight);
        }
    }

    file.close();
    return true;
}

// Function to load passenger data from passengers.txt
bool FileManager::loadPassengers(std::vector<Flight>& flights) {
    std::ifstream file("data/passengers.txt");
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string flightId, firstName, lastName, phoneNumber, seat;
        int passengerId;

        // Note: The phone number and seat are single tokens in the example,
        // but the names are two tokens. We need to handle this.
        // The project description says:
        // "The first column shows flight id... followed by the first and last name of the passenger,
        // and his/her phone number. The next column shows the passenger’s seat... and the last field is an id number"
        
        // Simple stream extraction works if the names are single words, but the example shows "Tom Harris"
        // The simplest approach that aligns with basic C++ I/O is to assume single-word names or
        // to read the first two words as first and last name, which is a common simplification.
        // Let's stick to simple stream extraction for all fields, which implies single-word names
        // or a fixed-width/delimiter-based file format, which is not explicitly stated.
        // Given the course level, simple space-delimited reading is the most likely expectation.
        
        if (ss >> flightId >> firstName >> lastName >> phoneNumber >> seat >> passengerId) {
            Flight* flight = findFlightById(flights, flightId);
            if (flight) {
                // Note: Passenger constructor takes (firstname, lastname, row, seat, ID, PhoneNumber)
                // We need to extract row and seat from the combined string 'seat' and use the flightId from the Flight object.
                // Since the Flight and Passenger classes are not fully implemented by David, we will use the simplified constructor
                // and assume the Flight class will handle the correct assignment.
                // For now, we will use the simplified constructor that takes the components.
                // The Passenger constructor in Passenger.h is: Passenger(string firstname, string lastname, int row, char seat, int ID, string PhoneNumber);
                // The data in passengers.txt is: WJ1145 Tom Harris 403-100-0000 6A 10000
                // The stream extraction is: flightId, firstName, lastName, phoneNumber, seat, passengerId
                // We need to parse 'seat' (e.g., "6A") into row (int) and seat (char).
                
                // Assuming the first part of 'seat' is the row (int) and the last char is the seat (char)
                int row_num = 0;
                char seat_char = ' ';
                
                // Simple parsing for course level:
                if (seat.length() > 1) {
                    seat_char = seat.back();
                    std::string row_str = seat.substr(0, seat.length() - 1);
                    try {
                        row_num = std::stoi(row_str);
                    } catch (...) {
                        // Handle error if conversion fails, but for course level, assume valid input
                        row_num = 0;
                    }
                }
                
                Passenger newPassenger(firstName, lastName, row_num, seat_char, passengerId, phoneNumber);
                flight->addPassenger(newPassenger);
            }
        }
    }

    file.close();
    return true;
}

// Function to save all data back to files
bool FileManager::saveAllData(const std::vector<Flight>& flights) {
    // Save passengers to passengers.txt
    std::ofstream passengerFile("data/passengers.txt");
    if (!passengerFile.is_open()) {
        return false;
    }

    for (const auto& flight : flights) {
        for (const auto& passenger : flight.get_passengers()) {
            // Format: flightId firstName lastName phoneNumber seat passengerId
            // We need to use the public getters for all passenger data
            passengerFile << flight.get_flightNumber() << " "
                          << passenger.get_Firstname() << " "
                          << passenger.get_Lastname() << " "
                          << passenger.get_PhoneNumber() << " "
                          << passenger.get_seatandrow() << " "
                          << passenger.get_ID() << "\n";
        }
    }
    passengerFile.close();

    // Note: The project description does not explicitly require saving flights.txt,
    // as flight details (ID, cities, rows, seats) are assumed static.
    // We will only save the passenger data, as that is what changes.
    // If the user wants to save flights.txt, they can modify this.

    return true;
}
