/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Loan.h
*Description:  This file creates the Loan class by initializing the variables, creating constructors, and creating method headers.
*/

#include "Books.h"
#include "Patrons.h"
#include <iostream>
using namespace std;

class Loan {
  private:
    int loanID;
    int bookID;
    int patronID;
    string title;
    time_t dueDT;
    string currStatus;
    double fine;

  public:
    Loan () {
      loanID = 0;
      bookID = 0;
      patronID = 0;
      title = " ";
      dueDT = time(NULL);
      currStatus = " ";
      fine = 0;
    }

    Loan (int lID, int bID, int pID, string bTitle, time_t lDueDT, string lCurrStatus, double lFine) {
      loanID = lID;
      bookID = bID;
      title = bTitle;
      patronID = pID;
      dueDT = lDueDT;
      currStatus = lCurrStatus;
      fine = lFine;
    }

    int GetLoanID();
    int GetBookID();
    int GetPatronID();
    string GetTitle();
    time_t GetDueDT();
    string GetCurrStatus();
    double GetFine();

    void SetLoanID(int lID);
    void SetBookID(int bID);
    void SetPatronID(int pID);
    void SetTitle(string title);
    void SetDueDT(time_t lDueDT);
    void SetCurrStatus(string lCurrStatus);
    void SetFine(double lFine);
};
