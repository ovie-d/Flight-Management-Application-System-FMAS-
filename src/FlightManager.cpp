#include "FlightManager.h"
#include "Flight.h"
#include "Passenger.h"
#include <iostream>
#include <algorithm>

// Constructor
FlightManager::FlightManager() : selectedFlight(nullptr) {
    // The FileManager object is a member, so it is automatically constructed.
}

// Initialize: Load all data from files
void FlightManager::initialize() {
    if (fileManager.loadFlights(flights)) {
        // Now load passengers into the loaded flights
        if (fileManager.loadPassengers(flights)) {
            // Data loaded successfully
        } else {
            std::cerr << "Error: Could not load passenger data.\n";
        }
    } else {
        std::cerr << "Error: Could not load flight data.\n";
    }
}

// List all available flights
void FlightManager::listFlights() const {
    std::cout << "Available Flights:\n";
    for (size_t i = 0; i < flights.size(); ++i) {
        const auto& f = flights[i];
        std::cout << i + 1 << ". " << f.get_flightNumber() << " " << f.get_departureCity() << " to " << f.get_arrivalCity()
                  << " (" << f.get_number_of_rows() << " rows, " << f.get_number_of_seats_per_row() << " seats/row)\n";
    }
}

// Select a flight by ID
bool FlightManager::selectFlight(const std::string& flightId) {
    for (auto& f : flights) {
        if (f.get_flightNumber() == flightId) {
            selectedFlight = &f;
            return true;
        }
    }
    selectedFlight = nullptr;
    return false;
}

// Get the currently selected flight
Flight* FlightManager::getSelectedFlight() {
    return selectedFlight;
}

// Add a passenger to the currently selected flight
bool FlightManager::addPassenger(const Passenger& p) {
    if (selectedFlight) {
        // The Flight class (David's part) should handle the actual addition and seat validation
        selectedFlight->addPassenger(p);
        return true;
    }
    return false;
}

// Remove a passenger from the currently selected flight
bool FlightManager::removePassenger(int passengerId) {
    if (selectedFlight) {
        // The Flight class (David's part) should handle the actual removal
        return selectedFlight->removePassengerById(passengerId);
    }
    return false;
}

// Save all data back to files
bool FlightManager::saveData() {
    return fileManager.saveAllData(flights);
}

// Provide access to the internal flights vector for main.cpp
std::vector<Flight>& FlightManager::getFlights() {
    return flights;
}
