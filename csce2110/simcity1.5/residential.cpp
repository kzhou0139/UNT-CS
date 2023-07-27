/**
 * @file residential.cpp
 * @author Daisy Gan
 * @brief This is residential cell function definition file
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "residential.h"
#include <stdlib.h>
#include <time.h>

/**
 * @brief Construct a new Residential Cell:: Residential Cell object
 *
 * @param xPos
 * @param yPos
 * @param r
 */
ResidentialCell::ResidentialCell(int xPos, int yPos, Region* r) {
  x = xPos;
  y = yPos;
  population = 0;
  hasPower = false;
  type = "R";
  region = r;
  cats = 0;
  income = 0;
}
 //This details the overriden simulate function
 /**
  * @brief This defines the simulate function
  *
  */
void ResidentialCell::simulate() {
  bool increased = false;
  // initialize rnadom seed:
  srand(time(NULL));

  if (population == 0 && hasPower) {
    newPopulation = population + 1;
    region->setWorkers(region->getWorkers()+1);
    Worker *w; // intialize new worker
    region->getWorkerList().push_back(w); // add worker to workerList
    // create random income value and compare to cell's population
    // generate number between newPopulation and 7 and multiplying by 10,000 for total income (added from current income)
    income = income + (rand() % 7 + newPopulation)*10000;
    region->setIncome(income);
    if (income > (newPopulation*30000) && (income/10000)%newPopulation == 0) {
      cats++;
    }
    region->setCats(cats);
    increased = true;
  }
//The counter is used to determine location for population growth
  int cnt = 0;
  for (Cell* cell : adjList) {
    if (cell->getPopulation() >= 1) {
      cnt++;
    }
  }
//Every if statement uses a boolean for increased that is changed to make the function understand whether the needed increase has occured or not
  if (population == 0 && cnt >= 1 && !increased) {
    newPopulation = population + 1;
    region->setWorkers(region->getWorkers()+1);
    Worker *w;
    region->getWorkerList().push_back(w);
    income = income + (rand() % 7 + newPopulation)*10000;
    if (income > (newPopulation*30000) && (income/10000)%newPopulation == 0) {
      cats++;
    }
    increased = true;
  }

  if (population == 1 && cnt >= 2 && !increased) {
    newPopulation = population + 1;
    region->setWorkers(region->getWorkers()+1);
    Worker *w;
    region->getWorkerList().push_back(w);
    income = income + (rand() % 7 + newPopulation)*10000;
    if (income > (newPopulation*30000) && (income/10000)%newPopulation == 0) {
      cats++;
    }
    increased = true;
  }

  cnt = 0;
  for (Cell* cell : adjList) {
    if (cell->getPopulation() >= 2) {
      cnt++;
    }
  }

  if (population == 2 && cnt >= 4 && !increased) {
    newPopulation = population + 1;
    region->setWorkers(region->getWorkers()+1);
    Worker *w;
    region->getWorkerList().push_back(w);
    income = income + (rand() % 7 + newPopulation)*10000;
    if (income > (newPopulation*30000) && (income/10000)%newPopulation == 0) {
      cats++;
    }
    increased = true;
  }

  cnt = 0;
  for (Cell* cell : adjList) {
    if (cell->getPopulation() >= 3) {
      cnt++;
    }
  }
/**
 * @brief Construct a new if object
 *
 */
  if (population == 3 && cnt >= 6 && !increased) {
    newPopulation = population + 1;
    region->setWorkers(region->getWorkers()+1);
    Worker *w;
    region->getWorkerList().push_back(w);
    income = income + (rand() % 7 + newPopulation)*10000;
    if (income > (newPopulation*30000) && (income/10000)%newPopulation == 0) {
      cats++;
    }
    increased = true;
  }

  cnt = 0;
  for (Cell* cell : adjList) {
    if (cell->getPopulation() >= 4) {
      cnt++;
    }
  }

  if (population == 4 && cnt >= 8 && !increased) {
    newPopulation = population + 1;
    region->setWorkers(region->getWorkers()+1);
    Worker *w;
    region->getWorkerList().push_back(w);
    income = income + (rand() % 7 + newPopulation)*10000;
    if (income > (newPopulation*30000) && (income/10000)%newPopulation == 0) {
      cats++;
    }
    increased = true;
  }
}

//This determines the cells near the resident cell
/**
 * @brief This function defines which cells are near a particular resident cell
 *
 */
void ResidentialCell::adj() {
  for (int r = y-1; r <= y+1; r++) {
    if (r<0 || r>region->region.size()-1) {
      continue;
    }
    for (int c = x-1; c <= x+1; c++) {
      if (c<0 || c>region->region[0].size()-1) {
        continue;
      }
      if (r==y && c==x) {
        continue;
      }
      adjList.push_back(region->region[r][c]);
    }
  }
}
