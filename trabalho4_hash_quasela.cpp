#include <iostream>
#include <vector>

class HashTable {
private:
    struct Node {
        int value;
        bool occupied;
        
        Node() : value(0), occupied(false) {}
    };
    
    std::vector<Node> table;
    int tableSize;
    bool isInitialized;
    int size;  // Track number of elements

    int hashFunction(int x) {
        return x % tableSize;
    }

public:
    HashTable() : isInitialized(false), size(0) {}

    void insert(int value) {
        if (!isInitialized) {
            tableSize = value;
            table.resize(tableSize);
            isInitialized = true;
            return;
        }

        if (size >= tableSize) {
            std::cout << "Table is full" << std::endl;
            return;
        }

        int index = hashFunction(value);
        int originalIndex = index;
        
        while (table[index].occupied) {
            index = (index + 1) % tableSize;
            if (index == originalIndex) {
                std::cout << "Table is full" << std::endl;
                return;
            }
        }
        
        table[index].value = value;
        table[index].occupied = true;
        size++;
    }

    void remove(int value) {
        if (!isInitialized || size == 0) return;

        int index = hashFunction(value);
        int originalIndex = index;
        
        do {
            if (table[index].occupied && table[index].value == value) {
                // Mark this position as unoccupied
                table[index].occupied = false;
                size--;
                
                // Collect and rehash subsequent elements in the probe chain
                std::vector<int> elementsToRehash;
                int nextPos = (index + 1) % tableSize;
                
                // Collect elements until we find an empty slot
                while (table[nextPos].occupied) {
                    elementsToRehash.push_back(table[nextPos].value);
                    table[nextPos].occupied = false;
                    size--;
                    nextPos = (nextPos + 1) % tableSize;
                }
                
                // Reinsert all collected elements in their original order
                for (int elem : elementsToRehash) {
                    insert(elem);
                }
                return;
            }
            
            index = (index + 1) % tableSize;
        } while (index != originalIndex);
    }

    void list() {
        if (!isInitialized) {
            std::cout << "Table not initialized" << std::endl;
            return;
        }

        for (int i = 0; i < tableSize; i++) {
            if (table[i].occupied) {
                std::cout << table[i].value << std::endl;
            }
        }
    }
};

int main() {
    HashTable hash;
    char op;
    int value;

    while (std::cin >> op) {
        switch (op) {
            case 'i':
                std::cin >> value;
                hash.insert(value);
                break;
            case 'r':
                std::cin >> value;
                hash.remove(value);
                break;
            case 'l':
                hash.list();
                break;
        }
    }

    return 0;
}