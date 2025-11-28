#include <iostream>

bool quit = false;

int cont(){
    std::cout << "<<<<Press Return to continue>>>>" << std::endl;
    if (std::cin.get() == '\n') {
        return 1;
    }
    return 0;
}

void select(){
    std::cout << "<Please select one of the following options: \n>" << std::endl;
    std::cout << "  1. Select a flight." << std::endl;
    std::cout << "  2. Display flight seat map." << std::endl;
    std::cout << "  3. Display passengers information." << std::endl;
    std::cout << "  4. Add a new passenger." << std::endl;
    std::cout << "  5. Remove an existing passenger" << std::endl;
    std::cout << "  6. Save data." << std::endl;
    std::cout << "  7. Quit." << std::endl;

    std::cout << "\nEnter your choice (1-7) : " << std::endl;
    
    char choice = std::cin.get();

    switch (choice)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;
    case '7':
        quit = true;
        break;
    default:
        std::cout << "Invalid Entry." << std::endl;
        break;
    }
}

int main(){
    
    std::cout << "Version 1.0" << std::endl;
    std::cout << "Term Project - Flight Management Program in C++" << std::endl;
    std::cout << "Produced By : Alexander Gamble - Anes Khacha - David Onifeghara" << std::endl;
    std::cout << "Year : 2025 " << std::endl;
    
    cont();
    
    while (quit == false)
    {
        select();
        cont();
    }
    
    return 0;
}

