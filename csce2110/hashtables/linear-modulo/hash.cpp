/*In this implementation, the hashFunction method takes an integer key and calculates its modulus with the hash table size to determine
the bucket index. If the desired bucket is already occupied, the insert, get, and remove methods use linear probing to search for the
desired key in the hash table. The methods increment the current bucket index by 1 until an empty bucket is found or the entire hash
table has been searched. If an empty bucket is found, insert inserts the new item at that location; if the desired key is found, get
returns the corresponding value; and if the desired key*/

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
            // If the current bucket is already occupied, probe linearly
            hashIndex = (hashIndex + i) % size;
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
            // If the current bucket doesn't contain the desired key, probe linearly
            hashIndex = (hashIndex + i) % size;
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
            // If the current bucket doesn't contain the desired key, probe linearly
            hashIndex = (hashIndex + i) % size;
            i++;
        }
        if (table[hashIndex].key == key) {
            table[hashIndex].key = -1;
            table[hashIndex].value = "";
        }
    }
};
