/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Loan.h
*Description:  This file creates the Loans class by initializing the vector and creating method headers.
*/

#include "Loan.h"
#include <vector>
#include <ctime>

class Loans {
  private:
    vector<Loan> loanVec;
  public:
    void Checkout(int lID, string title, string name, Books &B, Patrons &P, Loans &L);
    void Checkin(int lID, string title, string name, Books &B, Patrons &P, Loans &L);
    void PrintOverdue();
    void PrintPatron(double bIDnum);
    void UpdateStatus();
    void Recheck(double bIDnum, Loans &L);
    void EditLoan(int lID, string currStatus, Loans &L);
    void ReportLost(string title, string name, Books &B, Patrons &P, Loans &L);
    void LoadLoans();
    void StoreLoans();
    int CountOverdue(int pID);
    void EditLoan2(int pID, string currStatus, Loans &L);
    bool NoOverdue(string name, Patrons &P);
    void Clear();
};
