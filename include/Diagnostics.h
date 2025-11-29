#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <iostream>
#include <string>

class Diagnostics {
public:
    // Simple function to print a diagnostic message
    static void log(const std::string& message);

    // Function to check data integrity (e.g., after loading)
    static bool checkDataIntegrity();
};

#endif // DIAGNOSTICS_H
