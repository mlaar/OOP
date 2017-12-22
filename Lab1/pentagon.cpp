#include "pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon(std::istream &is)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter coordinates by point № " << i + 1 << " ";
        is >> x[i];
        is >> y[i];
    };
}


double Pentagon::Square()
{
    double S = 0;
    for (int i = 0; i < 4; i++)
    {
        S = x[i] * y[i + 1] + S;
    };
    S = S + x[4] * y[0];
    for (int i = 0; i < 4; i++)
        S = S - x[i + 1] * y[i];
    S = S - x[0] * y[4];
    return std::abs(S / 2.0);
}

void Pentagon::Print()
{
    std::cout << "Pentagon: "
              << "\n";
    std::cout << "Coordinates of pentagon: "
              << "\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "X: " << x[i] << " Y: " << y[i] << std::endl;
    }
}

Pentagon::~Pentagon()
{
    std::cout << "Pentagon deleted" << std::endl;
}