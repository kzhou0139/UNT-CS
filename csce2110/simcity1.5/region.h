/**
 * @file region.h
 * @author Rhea Pookulangara
 * @brief Region header file containing getters and setters for every type of variable in the simulation
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef REGION_H
#define REGION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "cell.h"
#include "worker.h"
using namespace std;

/**
 * @brief Create region class
 *
 * @param timestep
 * @param workers
 * @param goods
 * @param refRate
 * @param timeLimit
 * @param region
 */
class Region{
    private:
    //Declaring data variables
    int timestep;
    int workers;
    vector<Worker*> workerList;
    int goods;
    int refRate;
    int timeLimit;
    int cats;
    int income;

    public:
    vector<vector<Cell*> > region; //This makes the data accesible by more files
    Region();
    //Setters and Getters to transfer data outside of cpp file
    /**
     * @brief Get the Timestep object
     *
     * @return int
     */
    int getTimestep();
    /**
     * @brief Set the Workers object
     *
     * @param w
     */
    void setWorkers(int w);
    /**
     * @brief Get the Workers object
     *
     * @return int
     */
    int getWorkers();
    /**
     * @brief Get the worker list
     *
     * @return vector
     */
    vector<Worker*> getWorkerList();
    /**
     * @brief Set the Goods object
     *
     * @param g
     */
    void setGoods(int g);
    /**
     * @brief Get the Goods object
     *
     * @return int
     */
    int getGoods();
    /**
     * @brief Set the Ref Rate object
     *
     * @param rr
     */
    void setRefRate(int rr);
    /**
     * @brief Set the Time Limit object
     *
     * @param tl
     */
    void setTimeLimit(int tl);
    /**
     * @brief Set the Power Access object
     *
     * @param x
     * @param y
     */
    void setPowerAccess(int x, int y);

    /**
     * @brief Declare the simulate function
     *
     */
    void simulate();
    /**
     * @brief Set the Region object
     *
     * @param r
     */
    void setRegion(vector<vector<Cell*> > &r);
    /**
     * @brief Declare the zoom function
     *
     */
    void zoom();
    /**
     * @brief Declare the print function
     *
     */
    void print();
    /**
     * @brief Declare the final output function
     *
     */
    void finalOutput();
    int getIncome();
    void setIncome(int n);
    int getCats();
    void setCats(int c);
};

#endif
