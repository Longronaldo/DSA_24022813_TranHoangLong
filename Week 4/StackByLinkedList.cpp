#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void addFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return head->data;
    }

    void display() const {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

class Stack {
private:
    LinkedList list;

public:
    void push(int val) {
        list.addFront(val);
    }

    void pop() {
        list.removeFront();
    }

    int top() const {
        return list.getFront();
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    void display() const {
        list.display();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();        

    cout << "Top: " << s.top() << endl;

    s.pop();
    s.display();        

    s.pop();
    s.pop();
    s.pop();             

    return 0;
}
