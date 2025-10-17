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
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void addBack(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFront() {
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return head->data;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class Queue {
private:
    LinkedList list;

public:
    void enqueue(int val) {
        list.addBack(val);
    }

    void dequeue() {
        list.removeFront();
    }

    int peek() const {
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
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout << "Peek: " << q.peek() << endl;
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}
