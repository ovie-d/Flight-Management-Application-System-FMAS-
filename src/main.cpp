#include <iostream>
#include <limits> // For numeric_limits
#include <string>
#include "FlightManager.h"
#include "Flight.h" // Assuming Flight.h is needed for Flight details
#include "SeatMap.h" // Alex's SeatMap header

// Global instance of FlightManager (since Singleton was removed)
FlightManager fm;

bool quit = false;

// Function to handle "Press Return to Continue"
void cont(){
    std::cout << "\n<<< Press Return to Continue>>>>" << std::endl;
    // Clear the input buffer before waiting for a new line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Function to display the main menu and handle user choice
void select(){
    std::cout << "\nPlease select one the following options:" << std::endl;
    std::cout << "  1. Select a flight" << std::endl;
    std::cout << "  2. Display Flight Seat Map." << std::endl;
    std::cout << "  3. Display Passengers Information." << std::endl;
    std::cout << "  4. Add a New Passenger." << std::endl;
    std::cout << "  5. Remove an Existing Passenger" << std::endl;
    std::cout << "  6. Save data" << std::endl;
    std::cout << "  7. Quit." << std::endl;

    int choice;
    std::cout << "Enter your choice (1, 2, 3, 4, 5, 6, or 7) ";
    
    // Read choice
    if (!(std::cin >> choice)) {
        // Handle invalid input (not an integer)
        std::cout << "Invalid Entry. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    // Clear the rest of the line after reading the integer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Switch to handle input
    switch (choice)
    {
    case 1:
        // Select a flight
        fm.listFlights();
        if (fm.getFlights().empty()) {
            std::cout << "No flights available to select.\n";
            break;
        }
        
        std::cout << "Enter the flight ID to select: ";
        std::string flightId;
        std::getline(std::cin, flightId);
        
        if (fm.selectFlight(flightId)) {
            Flight* selected = fm.getSelectedFlight();
            std::cout << "You have selected flight " << selected->get_flightNumber() << " from " 
                      << selected->get_departureCity() << " to " << selected->get_arrivalCity() << ".\n";
        } else {
            std::cout << "Error: Flight ID not found.\n";
        }
        break;
    case 2:
        // Display Flight Seat Map (Alex's part)
        if (fm.getSelectedFlight            // Alex's SeatMap display logic
            // NOTE: This requires Flight::getSeatMap to be implemented by David
            // For now, we use a placeholder array to make the call compile.
            int seatMap[24][6] = {0}; // Placeholder for actual seat map data
            displaySeatMap(fm.getSelectedFlight()->get_flightNumber(), seatMap); else {
            std::cout << "Please select a flight first (Option 1).\n";
        }
        break;
    case 3:
        // Display Passengers Information (David's part)
        if (fm.getSelectedFlight()) {
            // Placeholder for David's Passenger display logic
            std::cout << "Displaying Passengers for " << fm.getSelectedFlight()->get_flightNumber() << " (Placeholder for David's code).\n";
        } else {
            std::cout << "Please select a flight first (Option 1).\n";
        }
        break;
    case 4:
        // Add a New Passenger (David's part, using fm.addPassenger)
        if (fm.getSelectedFlight()) {
            // Placeholder for David's Add Passenger logic
            std::cout << "Adding new passenger to " << fm.getSelectedFlight()->get_flightNumber() << " (Placeholder for David's code).\n";
        } else {
            std::cout << "Please select a flight first (Option 1).\n";
        }
        break;
    case 5:
        // Remove an Existing Passenger (David's part, using fm.removePassenger)
        if (fm.getSelectedFlight()) {
            // Placeholder for David's Remove Passenger logic
            std::cout << "Removing passenger from " << fm.getSelectedFlight()->get_flightNumber() << " (Placeholder for David's code).\n";
        } else {
            std::cout << "Please select a flight first (Option 1).\n";
        }
        break;
    case 6:
        // Save data (Anes's part)
        if (fm.saveData()) {
            std::cout << "All data saved successfully to files.\n";
        } else {
            std::cout << "Error: Could not save data.\n";
        }
        break;
    case 7:
        // Quit
        quit = true;
        std::cout << "Program terminated.\n";
        break;
    default:
        std::cout << "Invalid Entry. Please enter a number between 1 and 7.\n";
        break;
    }
}

int main(){
    
    std::cout << "FMAS Version: 1.0" << std::endl;
    std::cout << "Term Project - Flight Management Application System" << std::endl;
    std::cout << "Produced By : Alexander Gamble - Anes Khacha - David Onifeghara" << std::endl;
    std::cout << "Year : 2025 " << std::endl;
    
    cont();
    
    // Initialize FlightManager (Anes's part)
    fm.initialize();
    
    while (quit == false)
    {
        select();
        if (!quit) {
            cont();
        }
    }
    
    return 0;
}
