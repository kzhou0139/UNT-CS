/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Books.h
*Description:  This file creates the Books class by initializing the vector and creating method headers.
*/

#ifndef BOOKS_H
#define BOOKS_H
#include "Book.h"
#include <vector>
#include <iostream>
using namespace std;

class Books {
  private:
    vector<Book> bookVec;
  public:
    void AddBook(string author, string title, string ISBNnum, double IDnum, double cost,string currStatus, Books &B);
    void EditBook(int bIndex, char action, Books &B);
    void DeleteBook(string title, Books &B);
    int FindBook(string title);
    void PrintBooks();
    void PrintBook(string title);
    int FindBookID(int bIndex);
    void LoadBooks();
    void StoreBooks();
    double FindCost(int bIndex);
    void EditBook2(string title, string currStatus, Books &B);
    void Clear();
};

#endif
