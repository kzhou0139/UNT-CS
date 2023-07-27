/**
 * @file worker.h
 * @author Kelly Zhou
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef WORKER_H
#define WORKER_H

#include <iostream>
using namespace std;

class Worker {
    /**
     * @brief The worker header adds years of experience and salary to the commercial and industrial classes
     *
     * @param yrsOfExp
     * @param totalSalary
     *
     */
    private:
    //Declaring data variables
    int yrsOfExp;
    int totalSalary;

    /**
     * @brief The public structure includes the setters and getters for years of experience and salary.
     *
     */
    public:
    /**
     * @brief Construct a new Worker object
     *
     */
    Worker();
    //Setters and Getters to transfer data outside of cpp file
    /**
     * @brief Get the Yrs Of Exp object
     *
     * @return int
     */
    int getYrsOfExp();
    /**
     * @brief Set the Yrs Of Exp object
     *
     * @param yoe
     */
    void setYrsOfExp(int yoe);
    /**
     * @brief Get the Total Salary object
     *
     * @return int
     */
    int getTotalSalary();
    /**
     * @brief Set the Total Salary object
     *
     * @param total
     */
    void setTotalSalary(int total);
};

#endif
