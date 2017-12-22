#include "trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze(std::istream &is)
{
    do
    {
        std::cout << "Enter first side: ";
        is >> side_1;
        std::cout << "Enter second side: ";
        is >> side_2;
        std::cout << "Enter the height: ";
        is >> height;
    } while ((side_1 <= 0) || (side_2 <= 0) || (height <= 0));
    std::cout << "Correct value"
              << "\n";
}

double Trapeze::Square()
{
    return ((side_1 + side_2) / 2) * height;
}

void Trapeze::Print()
{
    std::cout << "Trapeze: "
              << "\n";
    std::cout << "side 1:  " << side_1 << " side 2: " << side_2 << " height: " << height << std::endl;
}

Trapeze::~Trapeze()
{
    std::cout << "Trapeze deleted" << std::endl;
}