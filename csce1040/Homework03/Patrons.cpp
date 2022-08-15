/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Kelly Zhou
* UNT Email: kellyzhou@my.unt.edu
* Date submitted: 25 April 2022

*File name: Patrons.cpp
*Description:  This file contains the body of the functions declared in the Patrons.h file. The functions in this file
(AddPatron(), EditPatron(), DeletePatron(), FindPatron(), PrintPatrons(), PrintPatron(), NoOverdue(), PayFines(), FindPatronID(), LoadBooks(), StoreBooks()) serve the purpose of providing other files
the ability to edit the private variable declared in the Patrons.h file.
*/

#include <fstream>
#include <iostream>
using namespace std;
#include "Patrons.h"

/*
 Function:  AddPatron
 Parameters:  string name, int IDnum, double fine, int booksOut
 Return:  Nothing
 Description: This function uses the parameters to create a new Patron object then adds the new object to the patron vector.
*/
void Patrons::AddPatron(string name, int IDnum, double fine, int booksOut, Patrons& P) {
  Patron p(name, IDnum, fine, booksOut);
  patronVec.push_back(p);
  P.StorePatrons();
}

/*
 Function:  EditPatron
 Parameters:  int pIndex, char action, double fine
 Return:  Nothing
 Description: This function changes the patron's number of books out and fine balance based on the parameters that it's passed.
*/
void Patrons::EditPatron(int pIndex, char action, double fine, Patrons &P) {
  if (action == 'o')
    patronVec.at(pIndex).SetBooksOut(patronVec.at(pIndex).GetBooksOut()+1);
  if (action == 'i')
    patronVec.at(pIndex).SetBooksOut(patronVec.at(pIndex).GetBooksOut()-1);
  if (action == 'r') {
    patronVec.at(pIndex).SetBooksOut(patronVec.at(pIndex).GetBooksOut()-1);
    patronVec.at(pIndex).SetFineBalance(patronVec.at(pIndex).GetFineBalance()+fine);
  }
  P.StorePatrons();
}

/*
 Function:  EditPatron2
 Parameters:  string name, double fine
 Return:  Nothing
 Description: This function changes the patron's number of books out and fine balance based on the parameters that it's passed.
*/
void Patrons::EditPatron2(string name, double fine, Patrons &P) {
  for (int i = 0; i < patronVec.size(); i++) {
    if (patronVec.at(i).GetName() == name)
      patronVec.at(i).SetFineBalance(fine);
  }
  P.StorePatrons();
}

/*
 Function:  DeletePatron
 Parameters:  string name
 Return:  Nothing
 Description: This function deletes a patron from the patron vector using the parameter that it's passed.
*/
void Patrons::DeletePatron(string name, Patrons &P) {
  int notFound = 0;
  for (int i = 0; i < patronVec.size(); i++) {
    if (patronVec.at(i).GetName().compare(name) == 0) {
      patronVec.erase(patronVec.begin()+i);
      P.StorePatrons();
      notFound = 1;
      break;
    }
  }
  if (notFound == 0)
    cout<<"Patron not found. No one removed."<<endl;
  P.StorePatrons();
}

/*
 Function:  FindPatron
 Parameters:  string name
 Return:  an int varibale representing the index of a certain patron
 Description: This function finds the index of the patron with the name that is passed in the parameters.
*/
int Patrons::FindPatron(string name) {
  int notFound = 0;
  int ret;
  for (int i = 0; i < patronVec.size(); i++) {
    if (patronVec.at(i).GetName().compare(name) == 0) {
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
 Function:  PrintPatrons
 Parameters:  Nothing
 Return:  Nothing, but prints out the patron information
 Description: This function prints out the information for all the patrons
*/
void Patrons::PrintPatrons() {
  for (int i = 0; i < patronVec.size(); i++) {
    cout<<"Information for Patron #"<<i<<": "<<endl;
    cout<<"Name: "<<patronVec.at(i).GetName()<<endl;
    cout<<"ID Number: "<<patronVec.at(i).GetIDnum()<<endl;
    cout<<"Fine Balance: "<<patronVec.at(i).GetFineBalance()<<endl;
    cout<<"Current Number of Books Out: "<<patronVec.at(i).GetBooksOut()<<endl;
    if (i != patronVec.size() - 1)
      cout<<endl;
  }
}

/*
 Function:  PrintPatron
 Parameters:  Nothing
 Return:  Nothing, but prints out the patron information
 Description: This function prints out the information for the patron with the name that's passed in as a parameter
*/
void Patrons::PrintPatron(string name) {
  for (int i = 0; i < patronVec.size(); i++) {
    if (patronVec.at(i).GetName().compare(name) == 0) {
      cout<<"Name: "<<patronVec.at(i).GetName()<<endl;
      cout<<"ID Number: "<<patronVec.at(i).GetIDnum()<<endl;
      cout<<"Fine Balance: "<<patronVec.at(i).GetFineBalance()<<endl;
      cout<<"Current Number of Books Out: "<<patronVec.at(i).GetBooksOut()<<endl;
    }
  }
}

/*
 Function:  PayFines
 Parameters:  string name
 Return:  Nothing
 Description: This function deletes the loan that the patron has once the fine is payed. Additionally, it updates the patron's fine balance.
*/
void Patrons::PayFines(string name, Patrons &P) {
  for (int i = 0; i < patronVec.size(); i++) {
    if (patronVec.at(i).GetName() == name)
      patronVec.at(i).SetFineBalance(0);
  }
  cout<<"Fine has been paid."<<endl;
  P.StorePatrons();
}

/*
 Function:  FindPatronID
 Parameters:  int pIndex
 Return:  an int value representing the ID of a patron
 Description: This function returns the ID of the patron that's at the index passed in as a parameter
*/
int Patrons::FindPatronID(int pIndex) {
  int pID = patronVec.at(pIndex).GetIDnum();
  return pID;
}

/*
 Function:  FindBooksOut
 Parameters:  int pIndex
 Return:  an int value representing the number of books that the patron has out
 Description: This function returns the number of books that the patron that's at the index passed in as a parameter has checked out.
*/
int Patrons::FindBooksOut(int pIndex) {
  int booksOut = patronVec.at(pIndex).GetBooksOut();
  return booksOut;
}

/*
 Function:  LoadPatrons
 Parameters:  Nothing
 Return:  Nothing
 Description: This function reads in patron information and creates a patron object from the information. Then, the object is added to the patron vector.
*/
void Patrons::LoadPatrons() {
  ifstream patronsIn;
  patronsIn.open("Patrons.dat");
  string name;
  int IDnum;
  double fineBalance;
  int booksOut;

  int numPatrons; patronsIn >> numPatrons;
  for (int i = 0; i < numPatrons; i++) {
    patronsIn >> name;
    patronsIn >> IDnum;
    patronsIn >> fineBalance;
    patronsIn >> booksOut;
    Patron p(name, IDnum, fineBalance, booksOut);
    patronVec.push_back(p);
  }
  patronsIn.close();
}

/*
 Function:  Clear
 Parameters:  Nothing
 Return:  Nothing
 Description: This function clears the patron vector
*/
void Patrons::Clear() {
  patronVec.clear();
}

/*
 Function:  StorePatrons
 Parameters:  Nothing
 Return:  Nothing
 Description: This function writes the information stored in the patron vector into a data file called Patrons.dat
*/
void Patrons::StorePatrons() {
  ofstream patronsOut;
  patronsOut.open("Patrons.dat");
  patronsOut << patronVec.size() << endl;
  for (int i = 0; i < patronVec.size(); i++) {
    patronsOut << patronVec.at(i).GetName() << endl;
    patronsOut << patronVec.at(i).GetIDnum() << endl;
    patronsOut << patronVec.at(i).GetFineBalance() << endl;
    patronsOut << patronVec.at(i).GetBooksOut() << endl;
  }
  patronsOut.close();
}
