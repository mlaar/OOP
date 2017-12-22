#include "Pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon(std::istream &is)
{
    do {
        std::cout << "Enter the side: ";
        is >> side;
    } while (side <= 0);
    std::cout << "Correct value" << "\n";
            
}
    
double Pentagon::Square()
{
    return (5 * side * side) / (4 * tan(36));
}

void Pentagon::Print()
{
    std::cout << "Pentagon: "
              << "\n";
    std::cout << "Side: " << side << std::endl;
}

Pentagon::~Pentagon()
{
    std::cout << "Pentagon deleted" << std::endl;
}