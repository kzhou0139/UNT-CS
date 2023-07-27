/**
 * @file powerline.cpp
 * @author Rhea Pookulangara
 * @brief This defines the powerline function
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "powerline.h"

/**
 * @brief Construct a new Powerline:: Powerline object
 *
 * @param xPos
 * @param yPos
 * @param t
 */
//The powerline function only needs to include location and set the power to true as nothing else will be updated for this type of region
/**
 * @brief Construct a new Powerline:: Powerline object
 *
 * @param xPos
 * @param yPos
 * @param t
 */
Powerline::Powerline(int xPos, int yPos,  string t) {
  x = xPos;
  y = yPos;
  population = 0;
  hasPower = true;
  type = t;
}
