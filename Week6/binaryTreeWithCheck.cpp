#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insertNode(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isBSTUtil(Node* root, long minVal, long maxVal) {
    if (root == nullptr) return true;

    if (root->data <= minVal || root->data >= maxVal) 
        return false;

    return 
        isBSTUtil(root->left, minVal, root->data) &&
        isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "La Cay Nhi Phan\n";
    else
        cout << "Ko la cay nhi phan\n";

    return 0;
}
