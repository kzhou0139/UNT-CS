/**
 * @file industrial.cpp
 * @author Kelly Zhou
 * @brief This is the industrial cell function file
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "industrial.h"

/**
 * @brief Construct a new Industrial:: Industrial object
 *
 * @param xVal
 * @param yVal
 * @param r
 */
// constructor for Industrial object
Industrial::Industrial (int xVal, int yVal, Region* r){
  /**
   * @brief The parameters defined in this object are similar to those of the commercial file
   *
   * @param x
   * @param y
   * @param population
   * @param hasPower
   * @param type
   * @param region
   *
   */
  x = xVal;
  y = yVal;
  population = 0;
  hasPower = false;
  type = "I";
  region = r;
}

/**
 * @brief This determines the cells adjacent to the current industrial cell
 *
 * @param r
 * @param c
 */
//This determines the cells adjacent to the current industrial cell
void Industrial::adj(){
  for (int r = y-1; r <= y+1; r++) {
    if (r<0 || r>region->region.size()-1) { // checks if the row is out of bounds
      continue;
    }
    for (int c = x-1; c <= x+1; c++) {
      if (c<0 || c>region->region[0].size()-1) { // checks if the column is out of bounds
        continue;
      }
      if (r==y && c==x) { // checks to make sure that it's not the current cell
        continue;
      }
      adjList.push_back(region->region[r][c]); // adds the cell to adjList
    }
  }
}

/**
 * @brief The simulate function updates the number of available workers and goods
 *
 * @param increased
 * @param workers
 * @param cnt
 *
 */
//This updates the number of available workers and goods
/**
 * @brief The simulate function updates the number of available workers and goods
 *
 * @param increased
 * @param workers
 * @param cnt
 *
 */
void Industrial::simulate (){
  bool increased = false;
  int workers = region->getWorkers();

  if (population==0 && hasPower && workers >= 2) { // checks the criteria for whether or not information should be updated
    newPopulation++; // increases newPopulation by 1
    region->setWorkers(workers-2); // assign available workers to the job
    region->getWorkerList().erase(region->getWorkerList().begin()); // removes worker from worker list
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->setGoods(region->getGoods()+1); // distribute goods
    increased = true;
  }

  // count how many of the adjacent cells have a population of at least 1
  int cnt = 0;
  for (int i = 0; i < adjList.size(); i++) {
    if (adjList[i]->getPopulation() >= 1) {
      cnt++;
    }
  }

//This set of code works using a logic similar to the commercial regions
  if (population==0 && cnt>=1 && workers>=2 && !increased) {
    newPopulation++;
    region->setWorkers(workers-2);
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->setGoods(region->getGoods()+1);
    increased = true;
  }

  if (population==1 && cnt>=2 && workers >= 2 && !increased) {
    newPopulation++;
    region->setWorkers(workers-1);
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->setGoods(region->getGoods()+1);
    increased = true;
  }

  cnt = 0;
  for (int i = 0; i < adjList.size(); i++) {
    if (adjList[i]->getPopulation() >= 2) {
      cnt++;
    }
  }

  if (population==2 && cnt>=4 && workers >= 2 && !increased) {
    newPopulation++;
    region->setWorkers(workers-1);
    region->getWorkerList().erase(region->getWorkerList().begin());
    region->setGoods(region->getGoods()+1);
    increased = true;
  }
  /**
   * @brief Set and get workers using list and the salary/experience requirements
   *
   */

  vector<Worker*> workerList = region->getWorkerList(); // get list of workers
  for (int i = 0; i < workerList.size(); i++) { // loop through list of workers
    if (workerList.at(i)->getYrsOfExp() >= 2 && region->getGoods() >= 4) // checks criteria for determining how much the worker salary should be
      workerList.at(i)->setTotalSalary(workerList.at(i)->getTotalSalary() + 5000); // increases worker's salary
    else
      workerList.at(i)->setTotalSalary(workerList.at(i)->getTotalSalary() + 2500);
    workerList.at(i)->setYrsOfExp(workerList.at(i)->getYrsOfExp() + 1); // increases worker's years of experience
  }

  // controls the spread of pollution in the region
  pollution = max(population, pollution);
  int dist = population-1;
  for (int i = x-dist; i<=y+dist; i++) {
    if (i < 0 || i>=region->region.size()) { // checks if the cell is out of bounds
      continue;
    }
    for (int j = y-dist; j<=x+dist; j++) {
      if (j < 0 || j>=region->region[i].size()) { // checks if the cell is out of bounds
        continue;
      }
      if (i==x && j==y) { // checks that it's not the source cell
        continue;
      }

      region->region[i][j]->setPollution(max(population-max(abs(i-y), abs(j-x)), region->region[i][j]->getPollution())); // updates the cell's pollution
    }
  }
}
