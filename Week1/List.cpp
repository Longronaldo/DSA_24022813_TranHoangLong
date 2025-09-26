#include <iostream>
using namespace std;

const int MAX = 100;

class List {
private:
    int arr[MAX];
    int size;
public:
    List() {
        size = 0;
    }

    void printList() {
        if (size == 0) cout << "List is empty" << endl;
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
    bool insertHead(int value) {
        if (size == MAX) return false;
        for (int i = size; i >= 0; i--) arr[i + 1] = arr[i];
        arr[0] = value;
        size++;
        return true;
    }
    bool insertTail(int value) {
        if (size == MAX) return false;
        arr[size] = value;
        size++;
        return true;
    }
    bool deleteHead() {
        if (size == 0) return false;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
        return true;
    }
    bool deleteTail() {
        if (size == 0) return false;
        size--;
        return true;
    }
    int cutTail() {
        if (size == 0) return false;
        size--;
        return arr[size--];
    }
};

int main() {
    List l;
    l.insertHead(1);
    l.insertHead(2);
    l.insertHead(3);
    l.insertHead(4);
    l.insertHead(5);
    l.insertHead(6);

    l.deleteHead();
    l.printList();
}