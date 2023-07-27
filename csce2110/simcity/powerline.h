#ifndef POWERLINE_H
#define POWERLINE_H

#include <iostream>
#include <vector>
using namespace std;

#include "cell.h"
#include "region.h"

class Powerline : public Cell {
public:
  Powerline(int xPos, int yPos, string t);

  void simulate() override;
  void setAccessPower(vector<vector<Cell*>> region);
};

#endif
