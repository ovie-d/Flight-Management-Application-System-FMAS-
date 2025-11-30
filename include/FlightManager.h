#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include <vector>
#include <string>
#include "FileManager.h"

// Forward declarations for classes from other team members
class Flight;
class Passenger;

class FlightManager {
public:
    // Constructor
    FlightManager();

    // Core application logic functions
    void initialize();
    void listFlights() const;
    bool selectFlight(const std::string& flightId);
    Flight* getSelectedFlight();

    // Data manipulation functions
    bool addPassenger(const Passenger& p);
    bool removePassenger(int passengerId);
    
    // Data persistence
    bool saveData();

    // Provide access to the internal flights vector for main.cpp
    std::vector<Flight>& getFlights();

private:
    // Data members
    std::vector<Flight> flights;
    Flight* selectedFlight;
    FileManager fileManager;
};

#endif // FLIGHTMANAGER_H
