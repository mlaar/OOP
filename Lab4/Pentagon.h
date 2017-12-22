#ifndef PENTAGON_H
#define PENTAGON_H
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure
{
  public:
    Pentagon();
    Pentagon(std::istream &is);
    //double Square() override;
    void Print() override;
    virtual ~Pentagon();

  private:
    int side;
};

#endif
