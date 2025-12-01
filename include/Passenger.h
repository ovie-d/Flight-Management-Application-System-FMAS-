#ifndef Passenger_h
#define Passenger_h 

#include <string>
using namespace std;



class Passenger {
public:

    //constructor 
    Passenger();
    Passenger(string firstname, string lastname, int row, char seat, int ID, string PhoneNumber);

    // setters
    void changePassengerDetails(string firstname, string lastname, string PhoneNumber);
    void changePassengerFirstname(string firstname);
    void changePassengerLastname(string lastname);  
    void changePassengerPhoneNumber(string PhoneNumber);

    //destructor
    ~Passenger();
 
    // getters 
    string get_Firstname () const; 
    string get_Lastname () const;
    string get_fullname () const;
    char get_seat () const;
    int get_row ()const;
    string get_seatandrow ()const;
    int get_ID() const;
    string get_PhoneNumber() const;
    
private:
    string Firstname;
    string Lastname;
    int row;
    char seat;
    int ID;
    string PhoneNumber;



};