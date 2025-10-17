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

    void removeBack() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        --size;
    }

    int getBack() const {
        if (isEmpty()) return -1;
        return arr[size - 1];
    }

    void display() const {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Stack {
private:
    List list;

public:
    void push(int val) {
        list.addBack(val);
    }

    void pop() {
        list.removeBack();
    }

    int top() const {
        return list.getBack();
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
    s.push(100);
    s.push(200);
    s.push(300);
    s.display();          

    cout << "Top: " << s.top() << endl;

    s.pop();
    s.display();             

    s.pop();
    s.pop();
    s.pop();              

    return 0;
}
