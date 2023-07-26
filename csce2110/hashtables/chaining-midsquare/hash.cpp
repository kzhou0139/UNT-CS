/*In this updated implementation, the hashFunction method takes an integer key and calculates its square, then determines the number
of digits in the square using the log10 function. It then determines the number of digits in the middle of the square to use as the hash
value, based on the number of digits in the square. It divides the square by the appropriate divisor to extract the middle digits, then
takes the modulus with the hash table size to determine the bucket index. The rest of the implementation is the same as the previous
implementation.*/

#include "hash.h"

HashTable::HashTable(int size) {
    tableSize = size;
    table.resize(size);
}

void HashTable::insert(int value) {
    int hashIndex = hashFunction(value);
    HashItem item = { hashIndex, value };
    table[hashIndex].push_back(item);
}

void HashTable::get(int value) {
    int hashIndex = hashFunction(value);
    for (int i = 0; i < table[hashIndex].size(); i++) {
        if (table[hashIndex][i].value == value) {
            cout << "First instance of data item found" << endl;
            return;
        }
    }
    cout << "Element does not exist" << endl;
    return;
}

void HashTable::remove(int value) {
    int hashIndex = hashFunction(value);
    for (int i = 0; i < table[hashIndex].size(); i++) {
        if (table[hashIndex][i].value == value) {
            table[hashIndex].erase(table[hashIndex].begin() + i);
            cout << "Data element found and removed" << endl;
            return;
        }
    }
    cout << "Data element not found" << endl;
    return;
}

void HashTable::print() {
  for (int i = 0; i < table.size(); i++) {
    for (int j = 0; j < table[i].size(); j++)
      cout << "Bucket " << i << ": Key - " << table[i][j].key << " Value - " << table[i][j].value << endl;
  }
}

int HashTable::hashFunction (int key) {
    int square = key * key;
    int numDigits = floor(log10(square)) + 1;
    int middleDigits = (numDigits - 2) / 2;
    int divisor = pow(10, middleDigits);
    int middle = (square / divisor) % 10000;
    return middle % tableSize;
}
