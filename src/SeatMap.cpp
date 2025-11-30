#include <iostream>
#include <iomanip>
#include <string>



void displaySeatMap(const std::string& flightId, int seatMap[24][6]) {
    std::cout << "Aircraft Seat Map for flight " << flightId << std::endl;

    std::cout << std::setw(5) << "";

    for (int i = 0; i < 6; i++) {
        std::cout << std::setw(3) << char(('A') + i);
    }

    std::cout<<""<< std::endl;

    for (int row = 0; row < 24; ++row) {
        std::cout << std::setw(3) << row + 1 << " : ";
        for (int col = 0; col < 6; ++col) {
            if (seatMap[row][col] == 0) {
                std::cout << std::setw(3) << "[ ]"; // Available seat
            } else {
                std::cout << std::setw(3) << "[X]"; // Occupied seat
            }
        }
        std::cout << std::endl;
    }

}

