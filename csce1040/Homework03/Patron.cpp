/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Patron.cpp
*Description:  This file contains the body of the accessors/mutators declared in the Patron.h file. The accessors in this file
(GetName(), GetIDnum(), GetFineBalance(), GetBooksOut()) serve the purpose of providing other files
access to the private variables declared in the Patron.h file. None of the accessor methods require any inputs and all of them
output the value of the variable trying to be accessed. The mutators in this file (SetName(), SetIDnum(), SetFineBalance(),
SetBooksOut()) serve the purpose of allowing other files the ability to edit the private variables declared in the Patron.h file.
All of the mutator methods require the new value of the variable as an input and none of them have any output.
*/

#include "Patron.h"

string Patron::GetName() {
  return name;
}
int Patron::GetIDnum() {
  return IDnum;
}
double Patron::GetFineBalance() {
  return fineBalance;
}
int Patron::GetBooksOut() {
  return booksOut;
}

void Patron::SetName(string pName) {
  name = pName;
}
void Patron::SetIDnum(int pIDnum) {
  IDnum = pIDnum;
}
void Patron::SetFineBalance(double pFineBalance) {
  fineBalance = pFineBalance;
}
void Patron::SetBooksOut(int pBooksOut) {
  booksOut = pBooksOut;
}
