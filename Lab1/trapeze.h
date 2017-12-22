#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <iostream>
#include "figure.h"

class Trapeze : public Figure
{
  public:
    Trapeze();
    Trapeze(std::istream &is);
    double Square() override;
    void Print() override;
    virtual ~Trapeze();

  private:
    int side_1, side_2, height;
};

#endif