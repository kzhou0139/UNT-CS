/**
 * @file road.h
 * @author Rhea Pookulangara
 * @brief This declares applicable variables as roads within the simulation
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <vector>
using namespace std;

#include "cell.h"
#include "region.h"

/**
 * @brief Create a Cell object in the Road class
 *
 */
class Road : public Cell {
public:
  /**
   * @brief Construct a new Road object
   *
   * @param xPos
   * @param yPos
   * @param t
   */
  Road(int xPos, int yPos,string t){//Setting the variables. The most important part of roads is the location since they don't have populations or pollutions
    x = xPos;
    y = yPos;
    type = t;
    population = 0;
    pollution = 0;
    hasPower = false;}
  //Overriding the virtual void functions
  void simulate() override{}
  void adj() override{return;}
};

#endif
