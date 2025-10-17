#include <iostream>
using namespace std;

const int MAX = 100;

class List {
private:
    int arr[MAX];
    int size;

public:
    List() : size(0) {}

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == MAX;
    }

    void addBack(int val) {
        if (isFull()) {
            cout << "List is full.\n";
            return;
        }
        arr[size++] = val;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        for (int i = 1; i < size; ++i)
            arr[i - 1] = arr[i];
        --size;
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return arr[0];
    }

    void display() const {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Queue {
private:
    List list;

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
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();            

    cout << "Peek: " << q.peek() << endl; 

    q.dequeue();
    q.display();           

    q.dequeue();
    q.dequeue();

    return 0;
}
