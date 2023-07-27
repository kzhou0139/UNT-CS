/**
 * @file commercial.h
 * @author Vedh Vellore
 * @brief This is the header file respective to the Commercial cell class
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <vector>
#include <string>
#include "cell.h"
#include "region.h"

using namespace std;

/**
 * @brief Construct a new Commercial Cell object
 *
 */
class Commercial : public Cell{
    public:
    //Creating the commercial function and overriding the voids
    /**
     * @brief Construct a new Commercial object
     *
     * @param xVal
     * @param yVal
     * @param r
     */
    Commercial(int xVal, int yVal, Region* r);
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
    /**
     * @brief Create variables for supply and demand
     *
     * @param supply
     * @param demand
     *
     */
    int supply;
    int demand;

    private:
    //Using a region to define the location/attributes of cell
    Region* region;
};

#endif
