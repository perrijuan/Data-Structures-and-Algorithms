#include <iostream>
using namespace std;

enum Cor { N = 0, R = 1 };  // N = Black, R = Red

template <class K, class V>
struct KVPair {
    K key;
    V value;
    KVPair() {}
    KVPair(K k, V v) : key(k), value(v) {}
    K getKey() { return key; }
};

template <class K, class V>
struct node {
    KVPair<K,V> info;
    int size;
    bool color;
    node* left;
    node* right;
    node(K k, V v) : info(k, v), size(1), color(R), left(nullptr), right(nullptr) {}
};

template <class K, class V>
int nodeSize(node<K,V>* x) {
    return (x == nullptr) ? 0 : x->size;
}

template <class K, class V>
bool isRed(node<K,V>* x) {
    return x != nullptr && x->color == R;
}

template <class K, class V>
node<K,V>* rotateLeft(node<K,V>* h) {
    node<K,V>* x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = R;
    x->size = h->size;
    h->size = 1 + nodeSize(h->left) + nodeSize(h->right);
    return x;
}

template <class K, class V>
node<K,V>* rotateRight(node<K,V>* h) {
    node<K,V>* x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = R;
    x->size = h->size;
    h->size = 1 + nodeSize(h->left) + nodeSize(h->right);
    return x;
}

template <class K, class V>
void flipColors(node<K,V>* h) {
    h->color = !h->color;
    if (h->left) h->left->color = !h->left->color;
    if (h->right) h->right->color = !h->right->color;
}

template <class K, class V>
node<K,V>* balance(node<K,V>* h) {
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);
    h->size = 1 + nodeSize(h->left) + nodeSize(h->right);
    return h;
}

template <class K, class V>
node<K,V>* putNode(node<K,V>* h, K k, V v) {
    if (h == nullptr) return new node<K,V>(k, v);

    if (k < h->info.getKey())
        h->left = putNode(h->left, k, v);
    else if (k > h->info.getKey())
        h->right = putNode(h->right, k, v);
    else
        h->info.value = v; // Update value if key exists

    h = balance(h);
    return h;
}

template <class K, class V>
class RedBlackTree {
private:
    node<K,V>* root;

    void preOrderPrint(node<K,V>* h) {
        if (h == nullptr) return;
        cout << h->info.getKey() << (h->color == N ? 'N' : 'R') << " ";
        preOrderPrint(h->left);
        preOrderPrint(h->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void put(K k, V v) {
        root = putNode(root, k, v);
        if (root) root->color = N;
    }

    void printPreOrder() {
        preOrderPrint(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree<int, int> rb;
    int valor;
    while (cin >> valor) {
        rb.put(valor, valor);
    }
    rb.printPreOrder();
    return 0;
}