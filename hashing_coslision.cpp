#include <iostream>
#include <vector>

class HashTable {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    std::vector<Node*> table;
    int tableSize;

    int hash(int x) const {
        return x % tableSize;
    }

public:
    HashTable(int size) : tableSize(size) {
        table.resize(size, nullptr);
    }

    ~HashTable() {
        // Clean up all nodes
        for (int i = 0; i < tableSize; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
    }

    void insert(int value) {
        int index = hash(value);
        Node* newNode = new Node(value);
        
        // Insert at the beginning of the chain
        newNode->next = table[index];
        table[index] = newNode;
    }

    void remove(int value) {
        int index = hash(value);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->value == value) {
                if (prev == nullptr) {
                    // Removing first node in chain
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void list() const {
        // Print all values in order of table position
        for (int i = 0; i < tableSize; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                std::cout << current->value << std::endl;
                current = current->next;
            }
        }
    }
};

int main() {
    int size;
    std::cin >> size;
    
    HashTable hash(size);
    
    char command;
    int value;
    
    while (std::cin >> command) {
        switch (command) {
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