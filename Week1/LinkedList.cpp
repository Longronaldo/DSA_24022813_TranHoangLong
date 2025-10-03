#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SLL {
private:
    Node* head;
    int size = 0;

    void printReverseHelper(Node* node) {
        if (node == nullptr) {
            cout << "nullptr" << " ";
            return;
        }
        printReverseHelper(node->next);
        cout << node->data << " ";
    }
public:
    SLL() : head(nullptr) {}

    void print() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }

    ~SLL() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
    bool insertAt(int val, int pos) {
        if (pos < 0 || pos > size) return false;

        if (pos == 0) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* cur = head;
            for (int i = 0; i < pos - 1; i++) {
                cur = cur->next;
            }

            Node* newNode = new Node(val);

            newNode->next = cur->next;
            cur->next = newNode;
        }

        size++;
        return true;
    }

    bool deleteAt(int pos) {
        if (size == 0 || pos < 0 || pos > size - 1) return false;
        
        if (pos == 0) {
            Node* newNode = head;
            head = head->next;
            delete newNode;
        }
        else {
            Node* cur = head;
            for (int i = 0 ; i < pos - 1; i++) {
                cur = cur->next;
            }
            Node* newNode = cur->next;
            cur->next = cur->next->next;
            delete newNode;
        }

        size--;
        return true;
    }

    void printReverse() {
        printReverseHelper(head);
    }

    void reverseLinkedList() {
        Node* prev = nullptr;
        Node* cur = head;

        while (cur != nullptr) {
            Node* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        head = prev;
    }
};

int main() {
    SLL sll;
    
    sll.insertAt(1, 0);
    sll.insertAt(2, 0);
    sll.insertAt(3, 0);
    sll.insertAt(4, 0);
    sll.insertAt(5, 0);

    cout << "them Node vao vi tri 0: ";
    if (sll.insertAt(10, 0)) cout << "them duoc" << endl;
    else cout << "ko them duoc" << endl;

    sll.print();

    cout << "xoa Node o vi tri 8: ";
    if (sll.deleteAt(8)) cout << "xoa duoc" << endl;
    else cout << "ko xoa duoc" << endl;

    sll.print();
    
    sll.printReverse();
    cout << endl;

    sll.reverseLinkedList();
    sll.print();
}