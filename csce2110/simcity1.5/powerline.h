/**
 * @file powerline.h
 * @author Rhea Pookulangara
 * @brief Header for the powerline function
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef POWERLINE_H
#define POWERLINE_H

#include <iostream>
#include <vector>
using namespace std;

#include "cell.h"
#include "region.h"

/**
 * @brief Create Cell object in Powerline class
 *
 */
class Powerline : public Cell {
public:
  /**
   * @brief Construct a new Powerline object
   *
   * @param xPos
   * @param yPos
   * @param t
   */
  //This sets the location of the powerline which are viewed the same as powerplants
  Powerline(int xPos, int yPos, string t);
  //Override virtual functions
  void simulate() override{}
  void adj() override{}
};

#endif
