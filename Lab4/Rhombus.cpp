#include "Rhombus.h"
#include <iostream>
#include <cmath>

Rhombus::Rhombus(std::istream &is)
{
    do
    {
        std::cout << "Enter the angle: ";
        is >> angle;
        std::cout << "Enter the side: ";
        is >> side;
    } while ((angle <= 0) || (angle >= 180) || (side <= 0));
    std::cout << "Correct value"
              << "\n";
}

/*double Rhombus::Square()
{
    return side * side * sin((angle * M_PI) / 180);
}*/

void Rhombus::Print()
{
    std::cout << "Rhombus: "
              << "\n";
    std::cout << "angle: " << angle << " side: " << side << std::endl;
}

Rhombus::~Rhombus()
{
    std::cout << "Rhombus deleted" << std::endl;
}