/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Loan.cpp
*Description:  This file contains the body of the accessors/mutators declared in the Loan.h file. The accessors in this file
(GetLoanID(), GetBookID(), GetPatronID(), GetDueDT(), GetCurrStatus(), GetFine()) serve the purpose of providing other files
access to the private variables declared in the Loan.h file. None of the accessor methods require any inputs and all of them
output the value of the variable trying to be accessed. The mutators in this file (SetLoanID(), SetBookID(), SetPatronID(),
SetDueDT(), SetCurrStatus(), SetFine()) serve the purpose of allowing other files the ability to edit the private variables
declared in the Loan.h file. All of the mutator methods require the new value of the variable as an input and none of them
have any output.
*/

#include "Loan.h"

int Loan::GetLoanID() {
  return loanID;
}
int Loan::GetBookID() {
  return bookID;
}
int Loan::GetPatronID() {
  return patronID;
}
string Loan::GetTitle() {
  return title;
}
time_t Loan::GetDueDT() {
  return dueDT;
}
string Loan::GetCurrStatus() {
  return currStatus;
}
double Loan::GetFine() {
  return fine;
}

void Loan::SetLoanID(int lID) {
  loanID = lID;
}
void Loan::SetBookID(int bID) {
  bookID = bID;
}
void Loan::SetPatronID(int pID) {
  patronID = pID;
}
void Loan::SetTitle(string bTitle) {
  title = bTitle;
}
void Loan::SetDueDT(time_t lDueDT) {
  dueDT = lDueDT;
}
void Loan::SetCurrStatus(string lCurrStatus) {
  currStatus = lCurrStatus;
}
void Loan::SetFine(double lfine) {
  fine = lfine;
}
