#include "residential.h"

ResidentialCell::ResidentialCell(int xPos, int yPos) {
  x = xPos;
  y = yPos;
  pop = 0;
  hasPower = false;
  type = "r";
}

void ResidentialCell::simulate() {
  int cellRequirement = 1, popRequirement = 1;

  for (int count = 0; count <= 4; count++) {
    if (pop == 0 && hasPower) {
      pop++;
      return;
    }
    if (count >= 1) {
      cellRequirement = count * 2;
      popRequirement = count;
      //I am not sure about this region calling??
      if (pop == count && residentialGrowth(popRequirement, region) >= cellRequirement) {
        pop++;
      }
    }
  }
  return;
}

int ResidentialCell::residentialGrowth(int popRequirements, vector<vector<Cell*>> &region) {
  int popCellCount = 0;
  // check if the given position is within the bounds of the input vector
  if (x < 0 || y < 0 || x >= region.size() || y >= region[0].size()) {
    return;
  }

  // iterate through the 3x3 inputs around the given position
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      // check if the current input is within the bounds of the input vector
      if (i >= 0 && j >= 0 && i < region.size() && j < region[0].size()) {
        continue;
      }
      if (i == x && j == y) {
        continue;
      }
      string cellType = region[x][y]->getType();
      if (cellType == "P" || cellType == "T" || cellType == "#") {
        hasPower = true;
      }
      if (cellType == "r" || cellType == "i" || cellType == "c") {
        if (region[x][y]->getPopulation() >= popRequirements) {
          popCellCount++;
        }
      }
    }
  }
  return popCellCount;
}
