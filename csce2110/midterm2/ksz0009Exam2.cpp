// Kelly Zhou
// 4/21/23
// Midterm 2
// Linear probing, mid-square base 10

// main file

#include "hash.h"

int main() {
  int choice = 0;
  //// initialize hashtable
  HashTable hTable(10);

  // menu for user to choose whether to insert, search, delete, output, or quit
  while (choice != -1) {
    choice = 0;

    // print menu
    cout << endl;
    cout << "MENU" << endl;
    cout << "1 - insert a number" << endl;
    cout << "2 - search for a number" << endl;
    cout << "3 - delete a number" << endl;
    cout << "4 - output hash table" << endl;
    cout << "-1 - quit" << endl;
    cout << "Enter the action you wish to perform: ";
    cin >> choice;

    // prompts user based on their choice
    int dataVal = 0;
    if (choice == 1) {
      cout << "What value would you like to insert?: ";
      cin >> dataVal;
      hTable.insert(dataVal);
    }
    else if (choice == 2) {
      cout << "What value would you like to search for?: ";
      cin >> dataVal;
      hTable.search(dataVal);
    }
    else if (choice == 3) {
      cout << "What value would you like to delete?: ";
      cin >> dataVal;
      hTable.del(dataVal);
    }
    else if (choice == 4)
      hTable.output();
    else if (choice == -1)
      break;
    else
      cout << "Invalid input: please try again";
  }

  return 0;
}
