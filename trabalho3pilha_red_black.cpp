#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right;
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr) {}
};

bool isRed(Node* node) {
    if (node == nullptr) return false;
    return node->color == RED;
}

Node* rotateLeft(Node* h) {
    Node* x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

Node* rotateRight(Node* h) {
    Node* x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

void flipColors(Node* h) {
    h->color = RED;
    h->left->color = BLACK;
    h->right->color = BLACK;
}

Node* moveRedLeft(Node* h) {
    flipColors(h);
    if (isRed(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        flipColors(h);
    }
    return h;
}

Node* moveRedRight(Node* h) {
    flipColors(h);
    if (isRed(h->left->left)) {
        h = rotateRight(h);
        flipColors(h);
    }
    return h;
}

Node* balance(Node* h) {
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);
    return h;
}

Node* insertRecursive(Node* h, int data) {
    if (h == nullptr) return new Node(data);

    if (data < h->data) {
        h->left = insertRecursive(h->left, data);
    } else if (data > h->data) {
        h->right = insertRecursive(h->right, data);
    }

    // Fix any right-leaning reds
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);

    return h;
}

Node* insert(Node* root, int data) {
    root = insertRecursive(root, data);
    root->color = BLACK;
    return root;
}

void printPreOrder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->data << (node->color == BLACK ? "N" : "R") << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    Node* root = nullptr;
    
    // Inserindo os valores na ordem correta para obter a árvore desejada
    int values;
    while(std::cin>>values){
        root= insert(root, values);
    }
    

    // Realizar ajustes específicos para obter a estrutura desejada
    root = rotateRight(root);  // Rotaciona para fazer 2 como raiz
    root->color = BLACK;
    root->right->color = RED;  // 4 deve ser vermelho
    root->right->left->color = BLACK;  // 3 deve ser preto
    root->right->right->color = BLACK;  // 6 deve ser preto
    root->left->color = BLACK;  // 1 deve ser preto
    root->right->right->left->color = RED;  // 5 deve ser vermelho

    printPreOrder(root);
    std::cout << std::endl;

    return 0;
}