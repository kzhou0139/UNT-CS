/**
 * @file cell.h
 * @author Rhea Pookulangara
 * @brief Header file that creates the cell and ajacent virtual functions as well as initializes all variables
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CELL_H
#define CELL_H

using namespace std;
#include <string>

class Cell{
    public:
    /**
    * @brief Construct a new Cell object
    *
    */
    Cell(){
        /**
         * @brief Initialize variables to 0
         *
         * @param population
         * @param newPopulation
         * @param pollution
         * @param hasPower
         * @param x
         * @param y
         * @param type
         * @param cats
         * @param income
         */
        population = 0;
        newPopulation = 0;
        pollution = 0;
        hasPower = false;
        x, y =0;
        type = " ";
        cats = 0;
        income = 0;
    }
    /**
     * @brief Adjacency function
     *
     */
    virtual void adj() = 0;
    //Virtual so other functions can inherit it and override it
    /**
     * @brief Simulation function
     *
     */
    virtual void simulate() = 0;
    //Get and set population, pollution, power, and type. Also uses the new population function based on logic issues with updating cells
    /**
       * @brief Get population
       *
       * @return int
       */
    int getPopulation(){
        return population;
    }
    /**
     * @brief Set the Population object
     *
     * @param p
     */
    void setPopulation(int p){
        population = p;
    }
    /**
     * @brief Get the Pollution object
     *
     * @return int
     */
    int getPollution(){
        return pollution;
    }
    /**
    * @brief Set the Pollution object
    *
    * @param pl
    */
    void setPollution(int pl){
        pollution = pl;
    }
    /**
     * @brief Get the Power object
     *
     * @return true
     * @return false
     */
    bool getPower(){
        return hasPower;
    }
    /**
     * @brief Set the Power object
     *
     * @param po
     */
    void setPower(bool po){
        hasPower = po;
    }
    /**
    * @brief Set the Type object
    *
    * @param t
    */
    void setType(string t){
        type = t;
    }
    /**
     * @brief Get the Type object
     *
     * @return string
     */
    string getType(){
        return type;
    }
    /**
    * @brief Update the population
    *
    */
    void updatePop(){
        population = newPopulation;
    }
    /**
    * @brief Get the X object
    *
    * @return int
    */
    int getX(){
        return x;
    }
    /**
     * @brief Get the Y object
     *
     * @return int
     */
    int getY(){
        return y;
    }
    /**
     * @brief Set the Cats object
     *
     * @param c
     */
    void setCats(int c){
       cats = c;
   }
   /**
    * @brief Get the Cats object
    *
    * @return int
    */
   int getCats(){
       return cats;
   }
   /**
    * @brief Set the Income object
    *
    * @param n
    */
   void setIncome(int n){
       income = n;
   }
   /**
    * @brief Get the Income object
    *
    * @return int
    */
   int getIncome(){
       return income;
   }

    /**
     * @brief Declare the protected variables
     *
     * @param population
     * @param newPopulation
     * @param pollution
     * @param x
     * @param y
     * @param hasPower
     * @param type
     * @param adjList
     * @param cats
     * @param income
     *
     */
    protected:
    int population;
    int newPopulation; //We need to store the population to update it after the whole simulation is run
    int pollution;
    int x, y;
    int cats, income;
    bool hasPower;
    string type;
    vector<Cell*> adjList;
};

#endif
