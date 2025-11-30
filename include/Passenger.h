#ifndef Passenger_h
#define Passenger_h 

#include <string>




class Passenger {
public:

    //constructor 
    Passenger();
    Passenger(std::string firstname, std::string lastname, int row, char seat, int ID, std::string PhoneNumber);

    // setters
    void changePassengerDetails(std::string firstname, std::string lastname, std::string PhoneNumber);
    void changePassengerFirstname(std::string firstname);
    void changePassengerLastname(std::string lastname);  
    void changePassengerPhoneNumber(std::string PhoneNumber);

    //destructor
    ~Passenger();
 
    // getters 
    std::string get_Firstname () const; 
    std::string get_Lastname () const;
    std::string get_fullname () const;
    char get_seat () const;
    int get_row ()const;
   std::string get_seatandrow () const;
    int get_ID() const;
    std::string get_PhoneNumber() const;

private:
    std::string Firstname;
    std::string Lastname;
    int row;
    char seat;
    int ID;
    std::string PhoneNumber;



};