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
                Passenger newPassenger(flightId, firstName, lastName, phoneNumber, seat, passengerId);
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
        for (const auto& passenger : flight.passengers) {
            // Format: flightId firstName lastName phoneNumber seat passengerId
            passengerFile << flight.id << " "
                          << passenger.firstName << " "
                          << passenger.lastName << " "
                          << passenger.phoneNumber << " "
                          << passenger.seat << " "
                          << passenger.id << "\n";
        }
    }
    passengerFile.close();

    // Note: The project description does not explicitly require saving flights.txt,
    // as flight details (ID, cities, rows, seats) are assumed static.
    // We will only save the passenger data, as that is what changes.
    // If the user wants to save flights.txt, they can modify this.

    return true;
}
