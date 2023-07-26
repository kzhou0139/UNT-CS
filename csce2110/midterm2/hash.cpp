// Kelly Zhou
// CSCE 2110.001 Midterm 2
// Linear probing, mid-square base 10

// // HashTable object .cpp file

#include "hash.h"

// HashTable constructor
HashTable::HashTable(int size) {
  tableSize = size;
  hTable.resize(size);
}

// hash function
int HashTable::midsquare_hash(int val) {
  int valSq = val * val; // square the user-enetered value
  int numDig = 0;
  int temp = val;

  // count the number of digits in the user-entered value
  while (temp > 0) {
    numDig++;
    temp /= 10;
  }

  int mid = numDig / 2;
  int off = (numDig % 2 == 0) ? 0 : 1;
  // base 10
  int div = pow(10, mid);
  int hIndex = (valSq / div) % (int)(pow(10, mid + off));

  return hIndex % tableSize;
}

// insert user-entered data into hashtable
void HashTable::insert(int value) {
  // get hash index and create a hash element
  int hIndex = midsquare_hash(value);
  HashElem elem = {hIndex, value};

  if (hTable[hIndex].empty()) { // if the location is empty, insert the element at the location
    hTable[hIndex].push_back(elem);
    return;
  }
  else { // if the location is not empty, find the next open location using linear probing
    int i = 0;
    while (!hTable[hIndex].empty()) {
      if (i == tableSize) { // collision strategy halt, no where to insert data
        cout << "Insert rejected" << endl;
        return;
      }
      hIndex = (hIndex+i) % tableSize; // linear probing
      i++;
    }
  }
  elem = {hIndex, value}; // if a location is found, the data is inserted
  hTable[hIndex].push_back(elem);
  return;
}

// search function
void HashTable::search(int value) {
  int hIndex = midsquare_hash(value);

  // find the index of the user-enetered value
  int i = 0;
  while (!hTable[hIndex].empty() && hTable[hIndex][0].key != hIndex && i <= tableSize) {
    hIndex = (hIndex+i) % tableSize;
    i++;
  }

  // if the index is found, print a statement to let the user know
  // if the index is not found, print a statement to let the user know
  if (hTable[hIndex][0].key == hIndex && hTable[hIndex][0].value == value) {
    cout << "First instance of data value found" << endl;
    return;
  }
  else {
    cout << "Data value not found" << endl;
    return;
  }
}

// delete function
void HashTable::del(int value) {
  int hIndex = midsquare_hash(value);

  // find the index of the user-enetered value
  int i = 0;
  while (!hTable[hIndex].empty() && hTable[hIndex][0].key != hIndex && i <= tableSize) {
    hIndex = (hIndex+i) % tableSize;
    i++;
  }

  // if the index is found, delete the data and print a statement to let the user know
  // if the index is not found, print a statement to let the user know
  if (hTable[hIndex][0].key == hIndex && hTable[hIndex][0].value == value) {
    hTable[hIndex].clear();
    cout << "Data value found and removed" << endl;
    return;
  }
  else {
    cout << "Data value not found" << endl;
    return;
  }
}

// print function
void HashTable::output() {
  // loop through the hashtable and print out the key and value of each element
  for (int i = 0; i < hTable.size(); i++) {
    for (int j = 0; j < hTable[i].size(); j++) {
      cout << "Key: " << hTable[i][j].key << " Value: " << hTable[i][j].value << endl;
    }
  }
}
