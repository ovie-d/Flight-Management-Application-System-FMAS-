#include "../include/FileManager.h"
#include "../include/Flight.h"
#include "../include/Passenger.h"
#include <sstream>
#include <iostream>

// Helper function to find a flight by ID
Flight* findFlightById(std::vector<Flight>& flights, const std::string& flightId) {
    for (auto& flight : flights) {
        if (flight.get_flightNumber() == flightId) {
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

        
        if (ss >> flightId >> firstName >> lastName >> phoneNumber >> seat >> passengerId) {
            Flight* flight = findFlightById(flights, flightId);
            if (flight) {
                
                int row_num = 0;
                char seat_char = ' ';
                
                if (seat.length() > 1) {
                    seat_char = seat.back();
                    std::string row_str = seat.substr(0, seat.length() - 1);
                    try {
                        row_num = std::stoi(row_str);
                    } catch (...) {
                        // Handle error if conversion fails
                        row_num = 0;
                    }
                }
                
                Passenger newPassenger(firstName, lastName, row_num, seat_char, passengerId, phoneNumber);
                flight->add_passenger(newPassenger);
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

    return true;
}
