#include "Trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze() : side_1(1), side_2(1), height(1)
{
    std::cout << "Trapeze created: " << std::endl;
}

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

Trapeze::Trapeze(const Trapeze& orig) {
    std::cout << "Trapeze copy created" << "\n";
    side_1 = orig.side_1;
    side_2 = orig.side_2;
    height = orig.height;
}

double Trapeze::Square()
{
    return ((side_1 + side_2) / 2) * height;
}

Trapeze& Trapeze::operator=(const Trapeze& right) {
    if (this == &right) return *this;

    std::cout << "Trapeze copied" << "\n";
    side_1 = right.side_1;
    side_2 = right.side_2;
    height = right.height;

    return *this;
}

void Trapeze::Print()
{
    std::cout << "Trapeze: "
              << "\n";
    std::cout << "side 1:  " << side_1 << " side 2: " << side_2 << " height: " << height << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
    os << "a = " << obj.side_1 << ", b = " << obj.side_2 << ", h = " << obj.height;
    return os;
}

std::istream& operator>>(std::istream& is, Trapeze& obj) {
    is >> obj.side_1;
    is >> obj.side_2;
    is >> obj.height;

    return is;
}

bool Trapeze::operator==(const Trapeze& right) {
    if ((side_1 == right.side_1) && (side_2 == right.side_2) && (height == right.height)) return true;
    else return false;
}

Trapeze::~Trapeze()
{
    std::cout << "Trapeze deleted" << std::endl;
}