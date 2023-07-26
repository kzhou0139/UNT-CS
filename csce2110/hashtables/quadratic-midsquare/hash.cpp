#include "hash.h"

HashTable::HashTable(int size) {
  tableSize = size;
  table.resize(size);
}

int HashTable::hashFunction(int key) {
  int square = key * key;
  int digits = 0;
  int temp = square;
  while (temp > 0) {
    digits++;
    temp /= 10;
  }
  int numDigitsToRemove = (digits - tableSize) / 2;
  int divisor = 1;
  for (int i = 0; i < numDigitsToRemove; i++) {
    divisor *= 10;
  }
  int truncated = square / divisor;
  return truncated % tableSize;
}

// Insert an item into the hash table
void HashTable::insert(int value) {
  int hashIndex = hashFunction(value);
  HashItem item = {hashIndex, value};

  if (table[hashIndex].empty()) {
    table[hashIndex].push_back(item);
    return;
  } else {
    int i = 0;
    while (!table[hashIndex].empty()) {
      if (i == tableSize) {
        cout << "Insert rejected" << endl;
        return;
      }
      // If the current bucket is already occupied, probe linearly
      hashIndex = (hashIndex + i * i) % tableSize;
      i++;
    }
  }
  item = {hashIndex, value};
  table[hashIndex].push_back(item);
  return;
}

// Get the value associated with a key
void HashTable::get(int value) {
  int hashIndex = hashFunction(value);
  // HashItem item = {hashIndex, value};

  int i = 0;
  while (!table[hashIndex].empty() && table[hashIndex][0].key != hashIndex) {
    if (i == tableSize) {
      cout << "Data element not found" << endl;
      return;
    }
    // If the current bucket is already occupied, probe linearly
    hashIndex = (hashIndex + i * i) % tableSize;
    i++;
  }

  if (table[hashIndex][0].key == hashIndex &&
      table[hashIndex][0].value == value) {
    cout << "First instance of data value found" << endl;
    return;
  }
}

// Remove an item from the hash table
void HashTable::remove(int value) {
  int hashIndex = hashFunction(value);
  int i = 0;

  while (!table[hashIndex].empty() && table[hashIndex][0].key != hashIndex) {
    if (i == tableSize) {
      cout << "Data element not found" << endl;
      return;
    }
    // If the current bucket is already occupied, probe linearly
    hashIndex = (hashIndex + i * i) % tableSize;
    i++;
  }

  if (table[hashIndex][0].key == hashIndex &&
      table[hashIndex][0].value == value) {
    table[hashIndex].clear();
    cout << "Data element found and removed" << endl;
  }
}

void HashTable::print() {
  for (int i = 0; i < table.size(); i++) {
    for (int j = 0; j < table[i].size(); j++)
      cout << "Bucket " << i << ": Key - " << table[i][j].key << " Value - "
           << table[i][j].value << endl;
  }
}
