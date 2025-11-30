#ifndef Flight_h
#define Flight_h 

#include <string>
#include <vector>
#include "Passenger.h"


class Flight {
public:
    //constructor 
    Flight();
    Flight(std::string flightNumber, std::string departureCity, std::string arrivalCity, int number_of_rows, int number_of_seats_per_row);

    // getters
    std::string get_flightNumber() const;
    std::string get_departureCity() const;
    std::string get_arrivalCity() const;
    std::vector<Passenger> get_passengers() const;
    int get_number_of_rows() const;
    int get_number_of_seats_per_row() const;

    // seat + passenger operations
    bool is_seat_taken(int row, char seat) const;
    bool add_passenger(const Passenger& passenger);
    bool remove_passenger(int ID);

       // display helpers
    void print_seat_map() const;                       
    void print_passenger_list() const; 
    
    // destructor
    ~Flight();

private:
    std::string flightNumber;
    std::string departureCity;
    std::string arrivalCity;
    std::vector <Passenger> passengers;
    int number_of_rows;
    int number_of_seats_per_row;

};
