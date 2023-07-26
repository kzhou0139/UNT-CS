// Kelly Zhou
// CSCE 2110.001 Midterm 2
// Linear probing, mid-square base 10

// HashTable object header file (Extra credit attempt)

#ifndef HASH_H
#define HASH_H

// include directives
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// HashElem struct
struct HashElem {
  int key;
  int value;
};

// HashTable class
class HashTable {
  // initialize private variables
  private:
    vector<vector<HashElem>> hTable;
    int tableSize;
    int midsquare_hash(int val);
    int secondHash(int val);
  // declare public constructor / functions
  public:
    HashTable(int size);
    void insert(int value);
    void search(int value);
    void del(int value);
    void output();
};

#endif
