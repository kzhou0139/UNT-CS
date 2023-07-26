#include <iostream>
using namespace std;

int main() {
  int choice = 0;
  HashTable table(10);

  while (choice != -1) {
    choice = 0;

    cout << "1 - insert a number" << endl;
    cout << "2 - search for a number" << endl;
    cout << "3 - delete a number" << endl;
    cout << "4 - output hash table" << endl;
    cout << "-1 - quit" << endl;
    cout << "Enter the action you wish to perform: ";
    cin >> choice;
    cout << endl;

    int input = 0;
    if (choice == 1) {
      cout << "What value would you like to insert?: " << endl;
      cin >> input;
      table.insert(input);
    }
    else if (choice == 2) {
      cout << "What value would you like to search for?: " << endl;
      cin >> input;
      table.get(input);
    }
    else if (choice == 3) {
      cout << "What value would you like to delete?: " << endl;
      cin >> input;
      table.remove(input);
    }
    else if (choice == 4)
      table.print();
    else
      break;
  }

  return 0;
}
