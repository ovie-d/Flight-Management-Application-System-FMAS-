#ifndef SEATMAP_H
#define SEATMAP_H

#include <string>

// Function to display the seat map (implemented in SeatMap.cpp)
// The actual seat map data should come from the Flight object.
void displaySeatMap(const std::string& flightId, int seatMap[24][6]);

#endif // SEATMAP_H
