#ifndef PENTAGON_H
#define PENTAGON_H
#include <iostream>
#include "figure.h"

class Pentagon : public Figure
{
  public:
    Pentagon();
    Pentagon(std::istream &is);
    double Square() override;
    void Print() override;
    virtual ~Pentagon();

  private:
    double x[5], y[5];
};

#endif
