#ifndef Flight_h
#define Flight_h 

#include <string>
#include <vector>
#include "Passenger.h"
using namespace std;

class Flight {
public:
    //constructor 
    Flight();
    Flight(string flightNumber, string departureCity, string arrivalCity, int number_of_rows, int number_of_seats_per_row);

    // getters
    string get_flightNumber() const;
    string get_departureCity() const;
    string get_arrivalCity() const;
    vector<Passenger> get_passengers() const;
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
    string flightNumber;
    string departureCity;
    string arrivalCity;
    vector <Passenger> passengers;
    int number_of_rows;
    int number_of_seats_per_row;

};
