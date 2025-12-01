#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include <fstream>


class Flight;
class Passenger;

class FileManager {
public:
    // Function to load flight data from flights.txt
    // Returns true on success, false on failure
    bool loadFlights(std::vector<Flight>& flights);

    // Function to load passenger data from passengers.txt
    // Returns true on success, false on failure
    bool loadPassengers(std::vector<Flight>& flights);

    // Function to save all data back to files
    // Returns true on success, false on failure
    bool saveAllData(const std::vector<Flight>& flights);

private:
    // Helper function to parse a single line from flights.txt
    Flight parseFlightLine(const std::string& line);

    // Helper function to parse a single line from passengers.txt
    Passenger parsePassengerLine(const std::string& line);
};

#endif // FILEMANAGER_H
