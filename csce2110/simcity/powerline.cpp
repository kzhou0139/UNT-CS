#include "powerline.h"

Powerline::Powerline(int xPos, int yPos, string t) {
  x = xPos;
  y = yPos;
  population = 0;
  hasPower = true;
  type = t;
}

void Powerline::setAccessPower(vector<vector<Cell*>> region) {
    for(int x1=x-1; x<x+1; x++) {
        for (int y1=y-1; y1<y+1; y++) {
            if (x1<0 || x1>=region.size() || y1<0 || y1>=region[0].size())
                continue;
            if (x1==x && y1==y)
                continue;

            region[x1][y1]->setPower(true);
        }
    }
}

void simulate() {return;}
