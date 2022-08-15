/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Book.cpp
*Description:  This file contains the body of the accessors/mutators declared in the Book.h file. The accessors in this file
(GetAuthor(), GetTitle(), GetISBNnum(), GetIDnum(), GetCost(), GetCurrStatus()) serve the purpose of providing other files
access to the private variables declared in the Book.h file. None of the accessor methods require any inputs and all of them
output the value of the variable trying to be accessed. The mutators in this file (SetAuthor(), SetTitle(), SetISBNnum(),
SetIDnum(), SetCost(), SetCurrStatus()) serve the purpose of allowing other files the ability to edit the private variables
declared in the Book.h file. All of the mutator methods require the new value of the variable as an input and none of them
have any output.
*/

#include "Book.h"

string Book::GetAuthor() {
  return author;
}
string Book::GetTitle() {
  return title;
}
string Book::GetISBNnum() {
  return ISBNnum;
}
double Book::GetIDnum() {
  return IDnum;
}
double Book::GetCost() {
  return cost;
}
string Book::GetCurrStatus() {
  return currStatus;
}

void Book::SetAuthor(string bAuthor) {
  author = bAuthor;
}
void Book::SetTitle(string bTitle) {
  title = bTitle;
}
void Book::SetISBNnum(string bISBNnum) {
  ISBNnum = bISBNnum;
}
void Book::SetIDnum(double bIDnum) {
  IDnum = bIDnum;
}
void Book::SetCost(double bCost) {
  cost = bCost;
}
void Book::SetCurrStatus(string bCurrStatus) {
  currStatus = bCurrStatus;
}
