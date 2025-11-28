#include <iostream>
#include <iomanip>
#include <string>

std::string flights[] = {"FM101", "FM102", "FM103", "FM104", "FM105"};

void displaySeatMap(int flightID, int seatMap[24][6]) {
    std::cout << "Seat Map for Flight " << flights[flightID] << std::endl;

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

int main() {
    int flightID = 0; // Example flight ID
    int seatMap[24][6] = {0}; // Example seat map initialization

    // Example: Mark some seats as occupied
    seatMap[0][0] = 1; // Seat A1 occupied
    seatMap[2][5] = 1; // Seat C6 occupied
    seatMap[23][5] = 1; // Seat F24 occupied

    displaySeatMap(flightID, seatMap);

    return 0;
}