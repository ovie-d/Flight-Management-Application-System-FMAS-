#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include <vector>
#include <string>
#include "FileManager.h"

// Forward declarations for classes handled by other team members
class Flight;
class Passenger;

class FlightManager {
public:
    // Singleton pattern implementation (since the task division mentions "Ensuring singleton data stores")
    static FlightManager& getInstance();

    // Core application logic functions
    void initialize();
    void listFlights() const;
    bool selectFlight(const std::string& flightId);
    Flight* getSelectedFlight();

    // Data manipulation functions (delegated to the selected flight object)
    bool addPassenger(const Passenger& p);
    bool removePassenger(int passengerId);
    
    // Data persistence
    bool saveData();

private:
    // Private constructor for Singleton
    FlightManager();
    // Delete copy constructor and assignment operator for Singleton
    FlightManager(const FlightManager&) = delete;
    FlightManager& operator=(const FlightManager&) = delete;

    // Data members
    std::vector<Flight> flights;
    Flight* selectedFlight;
    FileManager fileManager;
};

#endif // FLIGHTMANAGER_H
