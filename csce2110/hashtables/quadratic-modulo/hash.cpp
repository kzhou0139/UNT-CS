/*In this implementation, the hashFunction calculates the hash index as the key modulo the size of the hash table. If the current bucket
is already occupied, the insert, get, and remove methods probe quadratically to find the next available bucket. The quadratic probing
strategy is based on the formula hashIndex + i^2, where i is the number of probes.*/

#include <iostream>
#include <vector>

using namespace std;

// Define a struct for each item in the hash table
struct HashItem {
    int key;
    string value;
};

// Define the hash table class
class HashTable {
private:
    // The array to hold the hash table buckets
    vector<HashItem> table;

    // The size of the hash table (number of buckets)
    int size;

    // The hash function (using modulo)
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    // Insert an item into the hash table
    void insert(int key, string value) {
        int hashIndex = hashFunction(key);
        int i = 0;
        while (table[hashIndex].value != "") {
            // If the current bucket is already occupied, probe quadratically
            hashIndex = (hashIndex + i * i) % size;
            i++;
        }
        HashItem item = { key, value };
        table[hashIndex] = item;
    }

    // Get the value associated with a key
    string get(int key) {
        int hashIndex = hashFunction(key);
        int i = 0;
        while (table[hashIndex].key != key && table[hashIndex].value != "" && i < size) {
            // If the current bucket doesn't contain the desired key, probe quadratically
            hashIndex = (hashIndex + i * i) % size;
            i++;
        }
        if (table[hashIndex].key == key) {
            return table[hashIndex].value;
        }
        else {
            return "";
        }
    }

    // Remove an item from the hash table
    void remove(int key) {
        int hashIndex = hashFunction(key);
        int i = 0;
        while (table[hashIndex].key != key && table[hashIndex].value != "" && i < size) {
            // If the current bucket doesn't contain the desired key, probe quadratically
            hashIndex = (hashIndex + i * i) % size;
            i++;
        }
        if (table[hashIndex].key == key) {
            table[hashIndex].key = -1;
            table[hashIndex].value = "";
        }
    }
};
