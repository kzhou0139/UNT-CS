/**
 * @file residential.h
 * @author Daisy Gan
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef RESIDENTIALCELL_H
#define RESIDENTIALCELL_H

#include <iostream>
#include <vector>
using namespace std;

#include "cell.h"
#include "region.h"
#include "worker.h"

/**
 * @brief Create a Cell object in the ResidentialCell class
 *
 */
class ResidentialCell: public Cell {
public:
  /**
   * @brief Construct a new Residential Cell object
   *
   * @param xPos
   * @param yPos
   * @param r
   */
  ResidentialCell(int xPos, int yPos, Region* r);
//Virtual functions overriden and region used for collection of data
  void simulate() override;
  void adj() override;
private:
  Region* region;
};

#endif
