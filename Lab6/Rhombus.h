#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <iostream>
#include "Figure.h"

class Rhombus : public Figure
{
  public:
    Rhombus();
    Rhombus(std::istream &is);
    double Square() override;
    void Print() override;
    virtual ~Rhombus();

  private:
    double angle;
    double side;
};

#endif
