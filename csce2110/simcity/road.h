#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <vector>
using namespace std;

#include "cell.h"
#include "region.h"

class Road : public Cell {
public:
  Road(int xPos, int yPos);

  void simulate() override{}
};

#endif
