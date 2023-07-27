#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <vector>
#include <string>
#include "region.h"
#include "cell.h"

using namespace std;

class Commercial{
    public:
        Commercial();
        Commercial(int xVal, int yVal);

        int* adjIndex(vector<vector<cell>> &region, int adjSearch[], int i, int j);
        void CommercialUpdate(vector<vector<cell>> &region, int adjSearch[], int workers, int goods);

    private:
        int x, y;


};

#endif
