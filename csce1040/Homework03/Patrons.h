/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Patrons.h
*Description:  This file creates the Patrons class by initializing the vector and creating method headers.
*/

#ifndef PATRONS_H
#define PATRONS_H
#include "Patron.h"
#include <vector>
#include <iostream>
using namespace std;

class Patrons {
  private:
    vector<Patron> patronVec;
  public:
    void AddPatron(string name, int IDnum, double fine, int booksOut, Patrons &P);
    void EditPatron(int pIndex, char action, double fine, Patrons &P);
    void DeletePatron(string name, Patrons &P);
    int FindPatron(string name);
    void PrintPatrons();
    void PrintPatron(string name);
    void PayFines(string name, Patrons &P);
    int FindPatronID(int pIndex);
    int FindBooksOut(int pIndex);
    void LoadPatrons();
    void StorePatrons();
    void EditPatron2(string name, double fine, Patrons &P);
    void Clear();
};

#endif
