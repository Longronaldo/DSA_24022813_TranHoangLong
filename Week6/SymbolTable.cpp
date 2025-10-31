#include <iostream>
#include <vector>
using namespace std;

template <typename Key, typename Value>
class OrderedST {
private:
    struct Node {
        Key key;
        Value val;
        Node* left;
        Node* right;
        int size;

        Node(Key k, Value v, int s) : key(k), val(v), left(NULL), right(NULL), size(s) {}
    };

    Node* root = NULL;

    int size(Node* x) {
        return (x == NULL) ? 0 : x->size;
    }

    Node* put(Node* x, Key key, Value val) {
        if (x == NULL) return new Node(key, val, 1);
        if (key < x->key) x->left = put(x->left, key, val);
        else if (key > x->key) x->right = put(x->right, key, val);
        else x->val = val;
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node* min(Node* x) {
        if (x->left == NULL) return x;
        return min(x->left);
    }

    Node* deleteMin(Node* x) {
        if (x->left == NULL) return x->right;
        x->left = deleteMin(x->left);
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node* deleteMax(Node* x) {
        if (x->right == NULL) return x->left;
        x->right = deleteMax(x->right);
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node* floor(Node* x, Key key) {
        if (x == NULL) return NULL;
        if (key == x->key) return x;
        if (key < x->key) return floor(x->left, key);
        Node* t = floor(x->right, key);
        return (t != NULL) ? t : x;
    }

    Node* ceiling(Node* x, Key key) {
        if (x == NULL) return NULL;
        if (key == x->key) return x;
        if (key > x->key) return ceiling(x->right, key);
        Node* t = ceiling(x->left, key);
        return (t != NULL) ? t : x;
    }

    int rank(Key key, Node* x) {
        if (x == NULL) return 0;
        if (key < x->key) return rank(key, x->left);
        else if (key > x->key) return 1 + size(x->left) + rank(key, x->right);
        else return size(x->left);
    }

    Node* select(Node* x, int k) {
        if (x == NULL) return NULL;
        int t = size(x->left);
        if (t > k) return select(x->left, k);
        else if (t < k) return select(x->right, k - t - 1);
        else return x;
    }

public:
    int size() {
        return size(root);
    }

    void put(Key key, Value val) {
        root = put(root, key, val);
    }

    Key min() {
        return min(root)->key;
    }

    Key max() {
        Node* x = root;
        while (x->right != NULL) x = x->right;
        return x->key;
    }

    Key floor(Key key) {
        Node* x = floor(root, key);
        if (!x) throw runtime_error("No floor key");
        return x->key;
    }

    Key ceiling(Key key) {
        Node* x = ceiling(root, key);
        if (!x) throw runtime_error("No ceiling key");
        return x->key;
    }

    int rank(Key key) {
        return rank(key, root);
    }

    Key select(int k) {
        Node* x = select(root, k);
        if (!x) throw runtime_error("Invalid k");
        return x->key;
    }

    void deleteMin() {
        root = deleteMin(root);
    }

    void deleteMax() {
        root = deleteMax(root);
    }
};



int main() {
    OrderedST<int, string> st;
    st.put(5, "five");
    st.put(1, "one");
    st.put(9, "nine");
    st.put(3, "three");

    cout << "Min: " << st.min() << endl;
    cout << "Max: " << st.max() << endl;
    cout << "Floor(4): " << st.floor(4) << endl;
    cout << "Ceiling(4): " << st.ceiling(4) << endl;
    cout << "Rank(5): " << st.rank(5) << endl;
    cout << "Select(2): " << st.select(2) << endl;

    st.deleteMin();
    st.deleteMax();
    cout << "Size: " << st.size() << endl;
}
