#include "Pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon(std::istream &is)
{
    do
    {
        std::cout << "Enter the side: ";
        is >> side;
    } while (side <= 0);
    std::cout << "Correct value" << "\n";
            
}
    
/*double Pentagon::Square()
{
    double S = 0;
    /*for (int i = 0; i < 4; i++)
    {
        S = x[i] * y[i + 1] + S;
    };
    S = S + x[4] * y[0];
    for (int i = 0; i < 4; i++)
        S = S - x[i + 1] * y[i];
    S = S - x[0] * y[4];

    return (5*side*side)/(4*tan(36));
}*/

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