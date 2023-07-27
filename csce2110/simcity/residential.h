#ifndef RESIDENTIALCELL_H
#define RESIDENTIALCELL_H

#include <iostream>
#include <vector>
using namespace std;

#include "cell.h"
#include "region.h"

class ResidentialCell : public Cell {
public:
  ResidentialCell(int xPos, int yPos);

  void simulate() override;

  int residentialGrowth(int popRequirements, vector<vector<Cell*>> &region);

private:
  int x, y, pop;
  bool hasPower;
  string type;
  vector<vector<Cell*>> &region;
};

#endif
