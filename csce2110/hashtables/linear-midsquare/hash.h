#ifndef HASH_H
#define HASH_H

#include <iostream>
using namespace std;

struct HashItem {
    int key;
    int value;
};

class HashTable {
  private:
    vector<vector<HashItem>> table;
    int tableSize;
    int hashFunction (int key);
  public:
    HashTable(int size);
    void insert(int value);
    void get(int key);
    void remove(int key);
    void print();
};

#endif
