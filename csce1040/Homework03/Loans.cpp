/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Loans.cpp
*Description:  This file contains the body of the functions declared in the Loans.h file. The functions in this file
(Checkout(), Checkin(), PrintOverdue(), PrintPatron(), Recheck(), EditLoan(), ReportLost(), LoadLoans(), StoreLoans()) serve the purpose of providing other files
the ability to edit the private variable declared in the Loans.h file.
*/

#include "Loans.h"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

/*
 Function:  Checkout
 Parameters:  int lID, string title, string name, Books &B, Patrons &P
 Return:  Nothing
 Description: This function uses the parameters that are passed to it to create a new Loan object then adds the new object to the loan vector.
*/
void Loans::Checkout(int lID, string title, string name, Books &B, Patrons &P, Loans &L) {
  bool overdue = L.NoOverdue(name, P);
  if (overdue) {
    int bIndex = B.FindBook(title);
    B.EditBook(bIndex, 'o', B);
    int bID = B.FindBookID(bIndex);
    int pIndex = P.FindPatron(name);
    P.EditPatron(pIndex, 'o', 0, P);
    int pID = P.FindPatronID(pIndex);
    time_t today = time(NULL);
    struct tm* time = localtime(&today);
    time->tm_mday += 10;
    time_t due = mktime(time);
    //string dueDT = ctime(&due);
    Loan loan(lID, bID, pID, title, due, "out", 0);
    loanVec.push_back(loan);
    B.StoreBooks();
    P.StorePatrons();
    L.StoreLoans();
  }
  else
    cout<<"Sorry, you are ineligible to check out a book."<<endl;
}

/*
 Function:  Checkin
 Parameters:  int lID, string title, string name, Books &B, Patrons &P
 Return:  Nothing
 Description: This function uses the parameters that are passed to it to update the status of the book and patron. Additionally, this function uses the time library to see if the books is overdue. If the book is overdue, a fine is calculated and added to the patron's fine balance.
*/
void Loans::Checkin(int lID, string title, string name, Books &B, Patrons &P, Loans &L) {
  int bIndex = B.FindBook(title);
  B.EditBook(bIndex, 'i', B);
  int pIndex = P.FindPatron(name);
  P.EditPatron(pIndex, 'i', 0, P);
  int lIndex = 0;
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetLoanID() == lID)
      lIndex = i;
  }
  time_t today = time(NULL);
  struct tm* time = localtime(&today);
  time_t dueDT = mktime(time);
  double fineAmount;
  if (dueDT > loanVec.at(lIndex).GetDueDT()) {
    fineAmount = ((dueDT - loanVec.at(lIndex).GetDueDT()) * -1) * 0.25;
    P.EditPatron(pIndex, 'r', fineAmount, P);
  }
  B.StoreBooks();
  P.StorePatrons();
  L.StoreLoans();
}

/*
 Function:  PrintOverdue
 Parameters:  Nothing
 Return:  Nothing
 Description: This function prints out the information for all the books that are overdue.
*/
void Loans::PrintOverdue() {
  int count = 1;
  int notFound = 0;
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetCurrStatus() == "Overdue") {
      cout<<"Information for Overdue Book #"<<count<<": "<<endl;
      cout<<"Loan ID: "<<loanVec.at(i).GetLoanID()<<endl;
      cout<<"Book ID: "<<loanVec.at(i).GetBookID()<<endl;
      cout<<"Patron ID: "<<loanVec.at(i).GetPatronID()<<endl;
      cout<<"Due Date and Time: "<<loanVec.at(i).GetDueDT()<<endl;
      cout<<"Current Status: "<<loanVec.at(i).GetCurrStatus()<<endl;
      count++;
      notFound = 1;
    }
  }
  if (notFound == 0)
    cout<<"No books are overdue."<<endl;
}

/*
 Function:  PrintPatron
 Parameters:  double pIDnum
 Return:  Nothing
 Description: This function prints out the information for the patron with the ID number that's passed in as a parameter.
*/
void Loans::PrintPatron(double pIDnum) {
  int count = 1;
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetPatronID() == pIDnum) {
      cout<<"Book #"<<count<<" Title: "<<loanVec.at(i).GetTitle()<<endl;
      cout<<setw(9)<<" ID: "<<loanVec.at(i).GetBookID();
      count++;
    }
  }
}

/*
 Function:  NoOverdue
 Parameters:  string name, Patrons &P
 Return:  a bool value representing if the patron has overdue books or not
 Description: This function checks to see if the patron with the name that's passed in as a parameter is eligible to check out another book.
*/
bool Loans::NoOverdue(string name, Patrons& P) {
  int pIndex = P.FindPatron(name);
  int booksOut = P.FindBooksOut(pIndex);
  if (booksOut < 6)
    return true;
  else
    return false;
}

/*
 Function:  Recheck
 Parameters:  double IDnum
 Return:  Nothing
 Description: This function adds 10 days to the current due date of the loan.
*/
void Loans::Recheck(double bIDnum, Loans &L) {
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetBookID() == bIDnum) {
      time_t today = time(NULL);
      struct tm* time = localtime(&today);
      time->tm_mday += 10;
      time_t due = mktime(time);
      loanVec.at(i).SetDueDT(due);
      L.StoreLoans();
    }
  }
}

/*
 Function:  EditLoan
 Parameters:  int lID, string currStatus
 Return:  Nothing
 Description: This function uses the parameters that are passed to it to check and see if the loan's current status needs to be updated and updates it accordingly.
*/
void Loans::EditLoan(int lID, string currStatus, Loans &L) {
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetLoanID() == lID) {
      if (loanVec.at(i).GetCurrStatus() != currStatus)
        loanVec.at(i).SetCurrStatus(currStatus);
    }
  }
  L.StoreLoans();
}

/*
 Function:  EditLoan2
 Parameters:  int pID, string currStatus, Loans &L
 Return:  Nothing
 Description: This function uses the parameters that are passed to it to check and see if the loan's current status needs to be updated and updates it accordingly. Users do this one manually
*/
void Loans::EditLoan2(int pID, string currStatus, Loans &L) {
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetPatronID() == pID)
      loanVec.at(i).SetCurrStatus(currStatus);
  }
  L.StoreLoans();
}

/*
 Function:  ReportLost
 Parameters:  string title, string name, Books &B, Patrons &P
 Return:  Nothing
 Description: This function uses the parameters that are passed to it to update variables in books and patrons to indicate that the patron lost a book.
*/
void Loans::ReportLost(string title, string name, Books &B, Patrons &P, Loans &L) {
  int bIndex = B.FindBook(title);
  B.EditBook(bIndex, 'l', B);
  double cost = B.FindCost(bIndex);
  int pIndex = P.FindPatron(name);
  P.EditPatron(pIndex, 'r', cost, P);
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetTitle() == title)
      loanVec.erase(loanVec.begin()+i);
  }
  B.StoreBooks();
  P.StorePatrons();
  L.StoreLoans();
}

/*
 Function:  CountOverdue
 Parameters:  int pID
 Return:  an int value that represents the number of books that are overdue
 Description: This function counts the number of overdue books a patron has the returns that value
*/
int Loans::CountOverdue(int pID) {
  int overdue = 0;
  for (int i = 0; i < loanVec.size(); i++) {
    if (loanVec.at(i).GetPatronID() == pID && loanVec.at(i).GetCurrStatus() == "overdue")
      overdue++;
  }
  return overdue;
}

/*
 Function:  Clear
 Parameters:  Nothing
 Return:  Nothing
 Description: This function clears the loans vector
*/
void Loans::Clear() {
  loanVec.clear();
}

/*
 Function:  LoadLoans
 Parameters:  Nothing
 Return:  Nothing
 Description: This function reads in loan information and creates a loan object from the information. Then, the object is added to the loan vector.
*/
void Loans::LoadLoans() {
  ifstream loansIn;
  loansIn.open("Loans.dat");
  int loanID;
  int bookID;
  int patronID;
  string title;
  time_t dueDT;
  string currStatus;
  double fine;

  int numLoans; loansIn >> numLoans;
  for (int i = 0; i < numLoans; i++) {
    loansIn >> loanID;
    loansIn >> bookID;
    loansIn >> patronID;
    loansIn.ignore();
    getline(loansIn, title);
    loansIn >> dueDT;
    loansIn >> currStatus;
    loansIn >> fine;
    Loan l(loanID, bookID, patronID, title, dueDT, currStatus, fine);
    loanVec.push_back(l);
  }
}

/*
 Function:  StoreLoans
 Parameters:  Nothing
 Return:  Nothing
 Description: This function writes the information stored in the loan vector into a data file called Loans.dat
*/
void Loans::StoreLoans() {
  ofstream loansOut;
  loansOut.open("Loans.dat");
  loansOut << loanVec.size() << endl;
  for (int i = 0; i < loanVec.size(); i++) {
    loansOut << loanVec.at(i).GetLoanID()<<endl;
    loansOut << loanVec.at(i).GetBookID()<<endl;
    loansOut << loanVec.at(i).GetPatronID()<<endl;
    //time_t due = loanVec.at(i).GetDueDT();
    //struct tm* time = localtime(&due);
    //time_t due2 = mktime(time);
    //string dueDT = ctime(&due);
    //loansOut << loanVec.at(i).GetDueDT();
    //loansOut << dueDT;
    loansOut << loanVec.at(i).GetCurrStatus()<<endl;
    loansOut << loanVec.at(i).GetFine()<<endl;
  }
  loansOut.close();
}
