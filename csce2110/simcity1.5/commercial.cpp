/**
 * @file commercial.cpp
 * @author Vedh Vellore
 * @brief Commercial file including function definitions
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "commercial.h"

/**
 * @brief Construct a new Commercial:: Commercial object
 *
 * @param xVal
 * @param yVal
 * @param r
 */
Commercial::Commercial(int xVal, int yVal,  Region* r) {
    x = xVal;
    y = yVal;
    population = 0;
    hasPower = false;
    type = "C";
    region = r;
}

/**
 * @brief Construct a new Commercial::adj object to find the cell next to the current cell
 *
 */
void Commercial::adj(){
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

/**
 * @brief Define the simulate function based on the parameters of the Commercial cell
 *
 * @param increased
 * @param workers
 * @param goods
 *
 */
void Commercial::simulate (){
  adj();
  bool increased = false;
  int workers = region->getWorkers();
  int goods = region->getGoods();

  /**
   * @brief Construct an if statement to set population and increased value
   *
   */
  if (population==0 && hasPower && workers >= 1 && goods >= 1) {
    newPopulation++;
    region->setWorkers(workers-1);
    region->getWorkerList().erase(region->getWorkerList().begin()); // remove worker from workerList
    region->setGoods(goods-1);
    increased = true;
  }
  /**
   * @brief The cnt variable determines where the list is being parsed through
   *
   * @param cnt
   *
   */
  int cnt = 0;
  for (int i = 0; i < adjList.size(); i++) {
    if (adjList[i]->getPopulation() >= 1) {
      cnt++;
    }
  }
  if (population==0 && cnt>=1 && workers>=1 && goods>=1 && !increased) {
    newPopulation++;
    region->setWorkers(workers-1);
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->setGoods(goods-1);
    if (goods-1 == 0){
      demand++;
    }
    increased = true;
  }
  /**
   * @brief Construct a new if object to determine demand and supply
   *
   */
  if (population==1 && cnt>=2 && workers>=1 && goods>=1 && !increased) {
    newPopulation++;
    region->setWorkers(workers-1);
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->setGoods(goods-1);
    if (goods-1 == 0){
      demand++;
    }
    increased = true;
  }
  supply = goods;
}
