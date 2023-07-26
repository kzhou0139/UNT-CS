/*In this implementation, the size parameter passed to the constructor determines the number of buckets in the hash table. The
hashFunction method takes an integer key and returns a bucket index using the modulo operator. Each bucket holds a vector of HashItem
structs, each containing a key and a value. When an item is inserted, its key is hashed to determine the bucket index, and the item is
appended to the vector at that index. When an item is retrieved, its key is hashed to determine the bucket index, and a linear search is
performed within the vector at that index to find the matching key. When an item is removed, its key is hashed to determine the bucket
index, and a linear search is performed within the vector at that index to find the matching key and remove the corresponding item from the
vector.*/

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
    vector<vector<HashItem>> table;

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
        HashItem item = { key, value };
        table[hashIndex].push_back(item);
    }

    // Get the value associated with a key
    string get(int key) {
        int hashIndex = hashFunction(key);
        for (int i = 0; i < table[hashIndex].size(); i++) {
            if (table[hashIndex][i].key == key) {
                return table[hashIndex][i].value;
            }
        }
        return "";
    }

    // Remove an item from the hash table
    void remove(int key) {
        int hashIndex = hashFunction(key);
        for (int i = 0; i < table[hashIndex].size(); i++) {
            if (table[hashIndex][i].key == key) {
                table[hashIndex].erase(table[hashIndex].begin() + i);
                return;
            }
        }
    }
};
