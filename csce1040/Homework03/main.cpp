/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: main.cpp
*Description: Main file that interacts with user and gets user input.
*/

#include "Patrons.h"
#include "Books.h"
#include "Loans.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 Function:  PrintMainMenu
 Parameters:  Nothing
 Return:  Nothing, but prints out the menu
 Description: This function prints out the menu items
*/
void PrintMainMenu() {
  cout<<"MENU"<<endl;
  cout<<"1 - Add patron"<<endl;
  cout<<"2 - Delete patron"<<endl;
  cout<<"3 - Print patrons"<<endl;
  cout<<"4 - Print patron"<<endl;
  cout<<"5 - Add book"<<endl;
  cout<<"6 - Delete book"<<endl;
  cout<<"7 - Print books"<<endl;
  cout<<"8 - Print book"<<endl;
  cout<<"9 - Check out a book"<<endl;
  cout<<"10 - Check in a book"<<endl;
  cout<<"11 - List all overdue"<<endl;
  cout<<"12 - List all books for a particular patron"<<endl;
  cout<<"13 - Re-check a book"<<endl;
  cout<<"14 - Report lost"<<endl;
  cout<<"15 - Pay Fines"<<endl;
  cout<<"16 - Edit patron"<<endl;
  cout<<"17 - Edit book"<<endl;
  cout<<"18 - Edit loan"<<endl;
  cout<<"19 - Quit"<<endl;
}

/*
 Function:  Execute Menu
 Parameters:  int option, Books& B, Patrons& P, Loans& L
 Return:  Nothing, but prints out questions to prompt users for input
 Description: This function prompts users for input and calls various other functions in the Books/Patrons/Loans class based on the menu item that they chose.
*/
void ExecuteMenu(int option, Books& B, Patrons& P, Loans& L) {
  if (option == 1) {
    cout<<"ADD PATRON"<<endl;
    cout<<"What is your name?: ";
    string name;
    cin>>name;
    cout<<"What is your ID number?: ";
    int IDnum;
    cin>>IDnum;
    P.AddPatron(name, IDnum, 0, 0, P);
    //P.StorePatrons();
    cout<<"Patron Added"<<endl;
  }
  if (option == 2) {
    cout<<"DELETE PATRON"<<endl;
    cout<<"What is the name of the patron?: ";
    string name;
    cin>>name;
    P.DeletePatron(name, P);
    //P.StorePatrons();
    cout<<"Patron Deleted"<<endl;
  }
  if (option == 3) {
    cout<<"PRINT PATRONS"<<endl;
    P.PrintPatrons();
  }
  if (option == 4) {
    cout<<"PRINT PATRON"<<endl;
    cout<<"What is your name?: ";
    string name;
    cin>>name;
    P.PrintPatron(name);
  }
  if (option == 5) {
    cout<<"ADD BOOK"<<endl;
    cout<<"What is the name of the author?: ";
    string author;
    cin.ignore();
    getline(cin, author);
    cout<<"What is the title of the book?: ";
    string title;
    //cin.ignore();
    getline(cin, title);
    cout<<"What is the book's ISBN number?: ";
    string ISBNnum;
    cin>>ISBNnum;
    cout<<"What is the book's library ID number?: ";
    double IDnum;
    cin>>IDnum;
    cout<<"How much does the book cost?: ";
    double cost;
    cin>>cost;
    B.AddBook(author, title, ISBNnum, IDnum, cost, "in", B);
    //B.StoreBooks();
    cout<<"Book added"<<endl;
  }
  if (option == 6) {
    cout<<"DELETE BOOK"<<endl;
    cout<<"What is the name of the book?: ";
    string title;
    cin.ignore();
    getline(cin, title);
    B.DeleteBook(title, B);
    //B.StoreBooks();
    cout<<"Book deleted"<<endl;
  }
  if (option == 7) {
    cout<<"PRINT BOOKS"<<endl;
    B.PrintBooks();
  }
  if (option == 8) {
    cout<<"PRINT BOOK"<<endl;
    cout<<"What is the title of the book?: "<<endl;
    string title;
    cin.ignore();
    getline(cin, title);
    B.PrintBook(title);
  }
  if (option == 9) {
    cout<<"CHECK OUT A BOOK"<<endl;
    int lID;
    cout<<"What is the loan ID?: ";
    cin>>lID;
    cout<<"What is the title of the book that you want to check out?: ";
    string title;
    cin.ignore();
    getline(cin, title);
    cout<<"What is your name?: ";
    string name;
    cin>>name;
    L.Checkout(lID, title, name, B, P, L);
    //L.StoreLoans();
    cout<<"Book checked out"<<endl;
  }
  if (option == 10) {
    cout<<"CHECK IN A BOOK"<<endl;
    cout<<"What is the loan ID number?: ";
    int lID;
    cin>>lID;
    cout<<"What is the title of the book that you want to check in?: ";
    string title;
    cin.ignore();
    getline(cin, title);
    cout<<"What is your name?: ";
    string name;
    cin>>name;
    L.Checkin(lID, title, name, B, P, L);
    //L.StoreLoans();
    cout<<"Book returned"<<endl;
  }
  if (option == 11) {
    cout<<"LIST ALL OVERDUE"<<endl;
    L.PrintOverdue();
  }
  if (option == 12) {
    cout<<"LIST ALL BOOKS FOR A PARTICULAR PATRON"<<endl;
    cout<<"What is your ID number?: ";
    int pIDnum;
    cin>>pIDnum;
    L.PrintPatron(pIDnum);
  }
  if (option == 13) {
    cout<<"RE-CHECK A BOOK"<<endl;
    cout<<"What is the library ID of the book?: ";
    double bIDnum;
    cin>>bIDnum;
    L.Recheck(bIDnum, L);
    //L.StoreLoans();
    cout<<"Book rechecked"<<endl;
  }
  if (option == 14) {
    cout<<"REPORT LOST"<<endl;
    cout<<"What is the title of the book that you want to report lost?: ";
    string title;
    cin.ignore();
    getline(cin, title);
    cout<<"What is your name?: ";
    string name;
    cin>>name;
    L.ReportLost(title, name, B, P, L);
    //P.StorePatrons();
    //B.StoreBooks();
  }
  if (option == 15) {
    cout<<"PAY FINES"<<endl;
    cout<<"What is your name?: ";
    string name;
    cin>>name;
    P.PayFines(name, P);
  }
  if (option == 16) {
    cout<<"EDIT PATRON"<<endl;
    cout<<"What is the name of the patron you want to edit?: ";
    string name;
    cin>>name;
    cout<<"What is the new fine balance for the patron?: ";
    double fine;
    cin>>fine;
    P.EditPatron2(name, fine, P);
  }
  if (option == 17) {
    cout<<"EDIT BOOK"<<endl;
    cout<<"What is the title of the book you want to edit?: ";
    string title;
    cin.ignore();
    getline(cin, title);
    cout<<"What is the current status of the book?: ";
    string currStatus;
    cin>>currStatus;
    B.EditBook2(title, currStatus, B);
  }
  if (option == 18) {
    cout<<"EDIT LOAN"<<endl;
    cout<<"What is your ID number?: ";
    int pID;
    cin>>pID;
    cout<<"What's the current status of the loan?: ";
    string currStatus;
    cin>>currStatus;
    L.EditLoan2(pID, currStatus, L);
  }
}

int main() {
  cout << "+--------------------------------------------------+" << endl;
  cout << "          Computer Science and Engineering          " << endl;
  cout << "           CSCE 1040 - Computer Science II           " << endl;
  cout << "       Kelly Zhou ksz0009 kellyzhou@my.unt.edu      " << endl;
  cout << "+--------------------------------------------------+" << endl;

  Books B;
  Patrons P;
  Loans L;

  B.LoadBooks();
  P.LoadPatrons();
  L.LoadLoans();

  int option = 0;
  while (option != 19) {
    PrintMainMenu();
    cout<<"Select an option: ";
    cin>>option;
    if (option == 19)
      break;
    else
      ExecuteMenu(option, B, P, L);
    cout<<endl;
  }

  B.StoreBooks();
  P.StorePatrons();
  L.StoreLoans();

  B.Clear();
  P.Clear();
  L.Clear();
}
