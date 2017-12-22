#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Trapeze : public Figure
{
  public:
    Trapeze();
    Trapeze(std::istream &is);
    Trapeze(const Trapeze& orig);
    //double Square() override;
    void Print() override;    

    friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
    friend std::istream& operator>>(std::istream& is, Trapeze& obj);

    Trapeze& operator = (const Trapeze& right);
    bool operator == (const Trapeze& right);
    virtual ~Trapeze();
  private:
    int side_1, side_2, height;
};

#endif