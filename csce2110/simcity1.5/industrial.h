/**
 * @file industrial.h
 * @author Kelly Zhou
 * @brief This is the header file for the industrial class
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include <vector>
#include <string>
#include "cell.h"
#include "region.h"
using namespace std;

/**
 * @brief Create a new Cell object in the Industrial class
 *
 */
class Industrial: public Cell {
  public:
  //The virtual functions are overriden and the industrial region is found and stored using a pointer
    /**
     * @brief Construct a new Industrial object
     *
     * @param xVal
     * @param yVal
     * @param r
     */
    Industrial(int xVal, int yVal, Region* r);
    /**
     * @brief Override the adjacent function
     *
     */
    void adj() override;
    /**
     * @brief Override the simulate function
     *
     */
    void simulate() override;
  private:
    Region* region;
};

#endif
