#include "industrial.h"

// default constructor
Industrial::Industrial() {
  x = 0;
  y = 0;
}

// main constructor with inputs
Industrial::Industrial (int xVal, int yVal) {
  this->x = xVal;
  this->y = yVal;
}

// finds the indices for the cells adjacent to the cell at (r, c) and returns the values in an array
Industrial::adjIndex (vector<vector<cell>> &region, int adjSearch[], int r, int c) {
  //                  0          1        2         3
  // adjSearch = [row start, row end, col start, col end]

  // setting the row boundaries for the cells adjacent to the cell at (r, c)
  if (r == 0) {
    adjSearch[0] = 0;
    adjSearch[1] = 1;
  }
  else if (r == region.size()) {
    adjSearch[0] = r-1;
    adjSearch[1] = r;
  }
  else {
    adjSearch[0] = r-1;
    adjSearch[1] = r+1;
  }

  // setting the column boundaries for the cells adjacent to the cell at (r, c)
  if (c == 0) {
    adjSearch[2] = c;
    adjSearch[3] = c+1;
  }
  else if (c == region[0].size()) {
    adjSearch[2] = c-1;
    adjSearch[3] = c;
  }
  else {
    adjSearch[2] = c-1;
    adjSearch[3] = c+1;
  }
  return adjSearch;
}

// Updates the population of cells based on the number of people, power lines, and workers
// in the current cell and in adjacent cells
Industrial::IndustrialUpdate (vector<vector<cell>> &region, int workers, int goods) {
  for (int r = 0; r < region.size(); r++) { // loops through each row of the 2d vector
    for (int c = 0; c < region[0].size(); c++) { // loops through each column of the 2d vector
      int adjSearch[4]; // initializes the array that stores the indices of the cells adjacent to the cell at (r, c)
      if ((region[r][c] == 'R' || region[r][c] == 'I' || region[r][c] == 'C') && workers >= 2) {
        adjIndex(region, adjSearch, r, c); // finds the indices of the cells adjacent to the cell at (r, c)
        int plCount = 0; // initizles variable for storing the number of power lines in adjacent cells
        for (int i = adjSearch[0]; i <= adjSearch[1]; i++) { // loops through the adjacent indices to count the number of powerlines
          for (int j = adjSearch[2]; j <= adjSearch[3]; j++) {
            if (region[i][j] == 'T' || region[i][j] == '#')
              plCount++;
          }
        }
        if (plCount >= 1)
          region[r][c]++;
      }
      else if ((region[r][c] == 'R' || region[r][c] == 'I' || region[r][c] == 'C') && workers >= 2) {
        adjIndex(region, adjSearch, r, c);
        int popCount = 0;
        for (int i = adjSearch[0]; i <= adjSearch[1]; i++) {
          for (int j = adjSearch[2]; j <= adjSearch[3]; j++) {
            if (region[i][j] >= 1)
              popCount++;
          }
        }
        if (popCount >= 1)
          region[r][c]++;
      }
      else if (region[r][c] == 1 && workers >= 2) {
        adjIndex(region, adjSearch, r, c);
        int popCount = 0;
        for (int i = adjSearch[0]; i <= adjSearch[1]; i++) {
          for (int j = adjSearch[2]; j <= adjSearch[3]; j++) {
            if (region[i][j] >= 1)
              popCount++;
          }
        }
        if (popCount >= 2)
          region[r][c]++;
      }
      else if (region[r][c] == 2 && workers >= 2) {
        adjIndex(region, adjSearch, r, c);
        int popCount = 0;
        for (int i = adjSearch[0]; i <= adjSearch[1]; i++) {
          for (int j = adjSearch[2]; j <= adjSearch[3]; j++) {
            if (region[i][j] >= 2)
              popCount++;
          }
        }
        if (popCount >= 4)
          region[r][c]++;
      }
    }
  }
}

// Updates the pollution value of the cells adjacent to the cell at (x, y)
Industrial::PollutionUpdate (vector<vector<cell>> &region, int pollution, int x, int y) {
  int adjSearch[4];
  adjIndex(region, adjSearch, x, y); // finds the indices of the cells adjacent to the cell at (x, y)
  int pollNew = pollution -1;
  for (int i = adjSearch[0]; i <= adjSearch[1]; i++) { // loops through the adjacent cells to update the pollution of each cell
    for (int j = adjSearch[2]; j <= adjSearch[3]; j++) {
      region[i][j].setPollution(pollNew);
    }
  }
}

Industrial::GoodsToCommercial (vector<vector<cell>> &region, int goods)
