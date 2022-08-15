/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Books.cpp
*Description:  This file contains the body of the functions declared in the Books.h file. The functions in this file
(AddBook(), EditBook(), DeleteBook(), FindBook(), PrintBooks(), PrintBook(), FinfBookID(), FindCost(), Clear(), LoadBooks(), StoreBooks()) serve the purpose of providing other files
the ability to edit the private variable declared in the Books.h file.
*/

#include "Books.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 Function:  AddBoook
 Parameters:  string author, string title, string ISBNnum, double IDnum, double cost, string currStatus
 Return:  Nothing
 Description: This function uses the parameters to create a new Book object then adds the new object to the book vector.
*/
void Books::AddBook(string author, string title, string ISBNnum, double IDnum, double cost, string currStatus, Books &B) {
  Book b(author, title, ISBNnum, IDnum, cost, currStatus);
  bookVec.push_back(b);
  B.StoreBooks();
}

/*
 Function:  EditBook
 Parameters:  int bIndex, char action
 Return:  Nothing
 Description: This function changes the book's current status using the parameters that it's passed.
*/
void Books::EditBook(int bIndex, char action, Books &B) {
  if (action == 'o')
    bookVec.at(bIndex).SetCurrStatus("Out");
  if (action == 'i')
    bookVec.at(bIndex).SetCurrStatus("In");
  if (action == 'r')
    bookVec.at(bIndex).SetCurrStatus("Return");
  if (action == 'l')
    bookVec.at(bIndex).SetCurrStatus("Lost");
  B.StoreBooks();
}

/*
 Function:  EditBook2
 Parameters:  string title, string currStatus, Books &B
 Return:  Nothing
 Description: This function uses the parameters that are passed to it to check and see if the book's current status needs to be updated and updates it accordingly. Users do this one manually. manually
*/
void Books::EditBook2(string title, string currStatus, Books &B) {
  for (int i = 0; i < bookVec.size(); i++) {
    if (bookVec.at(i).GetTitle() == title)
      bookVec.at(i).SetCurrStatus(currStatus);
  }
  B.StoreBooks();
}
/*
 Function:  DeleteBook
 Parameters:  string title
 Return:  Nothing
 Description: This function deletes a book from the book vector using the parameter that it's passed.
*/
void Books::DeleteBook(string title, Books &B) {
  int notFound = 0;
  for (int i = 0; i < bookVec.size(); i++) {
    if (bookVec.at(i).GetTitle().compare(title) == 0) {
      bookVec.erase(bookVec.begin()+i);
      B.StoreBooks();
      notFound = 1;
      break;
    }
  }
  if (notFound == 0)
    cout<<"Book not found. Nothing removed."<<endl;
  B.StoreBooks();
}

/*
 Function:  FindBook
 Parameters:  string title
 Return:  an int varibale representing the index of a certain book
 Description: This function finds the index of the book with the title that is passed in the parameters.
*/
int Books::FindBook(string title) {
  int notFound = 0;
  int ret;
  for (int i = 0; i < bookVec.size(); i++) {
    if (bookVec.at(i).GetTitle() == title) {
      ret = i;
      notFound = 1;
      break;
    }
  }
  if (notFound == 0)
    return -1;
  else
    return ret;
}

/*
 Function:  PrintBooks
 Parameters:  Nothing
 Return:  Nothing, but prints out the book information
 Description: This function prints out the information for all the books
*/
void Books::PrintBooks() {
  int count = 1;
  for (int i = 0; i < bookVec.size(); i++) {
    cout<<"Information for Book #"<<count<<": "<<endl;
    cout<<"Title: "<<bookVec.at(i).GetTitle()<<endl;
    cout<<"Author: "<<bookVec.at(i).GetAuthor()<<endl;
    cout<<"ISBN Number: "<<bookVec.at(i).GetISBNnum()<<endl;
    cout<<"Library ID Number: "<<bookVec.at(i).GetIDnum()<<endl;
    cout<<"Cost: "<<bookVec.at(i).GetCost()<<endl;
    cout<<"Current Status: "<<bookVec.at(i).GetCurrStatus()<<endl;
    if (i != bookVec.size() - 1)
      cout<<endl;
    count++;
  }
}

/*
 Function:  PrintBook
 Parameters:  Nothing
 Return:  Nothing, but prints out book information
 Description: This function prints out the information of the book with the title that's passed in as a parameter.
*/
void Books::PrintBook(string title) {
  for (int i = 0; i < bookVec.size(); i++) {
    if (bookVec.at(i).GetTitle() == title) {
      cout<<"Author: "<<bookVec.at(i).GetAuthor()<<endl;
      cout<<"Title: "<<bookVec.at(i).GetTitle()<<endl;
      cout<<"ISBN Number: "<<bookVec.at(i).GetISBNnum()<<endl;
      cout<<"Library ID Number: "<<bookVec.at(i).GetIDnum()<<endl;
      cout<<"Cost: "<<bookVec.at(i).GetCost()<<endl;
      cout<<"Current Status: "<<bookVec.at(i).GetCurrStatus()<<endl;
    }
  }
}

/*
 Function:  FindBookID
 Parameters:  int bIndex
 Return:  an int value representing the ID of a book
 Description: This function returns the ID of the book with the index that's passed in as a parameter.
*/
int Books::FindBookID(int bIndex) {
  int bID = bookVec.at(bIndex).GetIDnum();
  return bID;
}

/*
 Function:  FindCost
 Parameters:  int bIndex
 Return:  a double value representing the cost of a book
 Description: This function returns the cost of the book with the index that's passed in as a parameter.
*/
double Books::FindCost(int bIndex) {
  int bCost = bookVec.at(bIndex).GetCost();
  return bCost;
}

/*
 Function:  Clear
 Parameters:  Nothing
 Return:  Nothing
 Description: Clears the bookVec vector
*/
void Books::Clear() {
  bookVec.clear();
}

/*
 Function:  LoadBooks
 Parameters:  Nothing
 Return:  Nothing
 Description: This function reads in book information and creates a book object from the information. Then, the object is added to the book vector.
*/
void Books::LoadBooks() {
  ifstream booksIn;
  booksIn.open("Books.dat");
  string author;
  string title;
  string ISBNnum;
  double IDnum;
  double cost;
  string currStatus;

  int numBooks; booksIn >> numBooks;
  for (int i = 0; i < numBooks; i++) {
    booksIn.ignore();
    getline(booksIn, author);
    //booksIn.ignore();
    getline(booksIn, title);
    booksIn >> ISBNnum;
    booksIn >> IDnum;
    booksIn >> cost;
    booksIn >> currStatus;
    Book b(author, title, ISBNnum, IDnum, cost, currStatus);
    bookVec.push_back(b);
  }
  booksIn.close();
}

/*
 Function:  StoreBooks
 Parameters:  Nothing
 Return:  Nothing
 Description: This function writes the information stored in the book vector into a data file called Books.dat
*/
void Books::StoreBooks() {
  ofstream booksOut;
  booksOut.open("Books.dat");
  booksOut << bookVec.size() << endl;
  for (int i = 0; i < bookVec.size(); i++) {
    booksOut << bookVec.at(i).GetAuthor() << endl;
    booksOut << bookVec.at(i).GetTitle() << endl;
    booksOut << bookVec.at(i).GetISBNnum() << endl;
    booksOut << bookVec.at(i).GetIDnum() << endl;
    booksOut << bookVec.at(i).GetCost() << endl;
    booksOut << bookVec.at(i).GetCurrStatus() << endl;
  }
  booksOut.close();
}
