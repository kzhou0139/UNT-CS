/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Patron.h
*Description:  This file creates the Patron class by initializing the variables, creating constructors, and creating method headers.
*/

#ifndef PATRON_H
#define PATRON_H
#include <iostream>
using namespace std;

class Patron {
  private:
    string name;
    int IDnum;
    double fineBalance;
    int booksOut;

  public:
    Patron () {
      name = " ";
      IDnum = 0;
      fineBalance = 0;
      booksOut = 0;
    }

    Patron (string pName, int pIDnum, double pFineBalance, int pBooksOut) {
      name = pName;
      IDnum = pIDnum;
      fineBalance = pFineBalance;
      booksOut = pBooksOut;
    }

    string GetName();
    int GetIDnum();
    double GetFineBalance();
    int GetBooksOut();

    void SetName(string pName);
    void SetIDnum(int pIDnum);
    void SetFineBalance(double pFineBalance);
    void SetBooksOut(int pBooksOut);
};

#endif
