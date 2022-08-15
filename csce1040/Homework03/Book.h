/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Book.h
*Description: This file creates the Book class by initializing the variables, creating constructors, and creating method headers.
*/

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book {
  private:
    string author;
    string title;
    string ISBNnum;
    double IDnum;
    double cost;
    string currStatus;

  public:
    Book () {
      author = " ";
      title = " ";
      ISBNnum = " ";
      IDnum = 0;
      cost = 0;
      currStatus = " ";
    }

    Book (string bAuthor, string bTitle, string bISBNnum, double bIDnum, double bCost, string bCurrStatus) {
      author = bAuthor;
      title = bTitle;
      ISBNnum = bISBNnum;
      IDnum = bIDnum;
      cost = bCost;
      currStatus = bCurrStatus;
    }

    string GetAuthor();
    string GetTitle();
    string GetISBNnum();
    double GetIDnum();
    double GetCost();
    string GetCurrStatus();

    void SetAuthor(string bAuthor);
    void SetTitle(string bTitle);
    void SetISBNnum(string bISBNnum);
    void SetIDnum(double bIDnum);
    void SetCost(double bCost);
    void SetCurrStatus(string bCurrStatus);
};

#endif
