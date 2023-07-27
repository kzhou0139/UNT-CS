#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

// include directives
#include <vector>
#include <string>
#include "region.h"
#include "cell.h"
using namespace std;

class Industrial {
  public:
    // Industrial class constructor declarations
    Industrial();
    Industrial(int xVal, int yVal);

    // Industrial class function declarations
    int * adjIndex (vector<vector<Cell*>> &region, int adjSearch[], int r, int c);
    void IndustrialUpdate (vector<vector<Cell*>> &region, int workers, int goods);
    void PollutionUpdate (vector<vector<Cell*>> &region, int pollution, int x, int y);
    void GoodsToCommercial (vector<vector<Cell*>> &region, int goods);
};

#endif
