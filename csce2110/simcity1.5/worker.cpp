/**
 * @file worker.cpp
 * @author Kelly Zhou
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "worker.h"

/**
 * @brief Construct a new Worker:: Worker object
 *
 */
Worker::Worker() { // worker constructor
    // initialize variables
    /**
     * @brief Initialize the years of experience and total salary of a worker to 0.
     *
     */
    yrsOfExp = 0;
    totalSalary = 0;
}

/**
 * @brief Get the years of experience of a worker
 *
 * @return int
 */
int Worker::getYrsOfExp(){
    return yrsOfExp;
}
/**
 * @brief Set the years of experience of a worker
 *
 * @param yoe
 */
void Worker::setYrsOfExp(int yoe) {
    yrsOfExp = yoe;
}
/**
 * @brief Get the worker's total salary
 *
 * @return int
 */
int Worker::getTotalSalary() {
    return totalSalary;
}
/**
 * @brief Set the worker's total salary
 *
 * @param total
 */
void Worker::setTotalSalary(int total) {
    totalSalary = total;
}
