#include <iostream>
#include <list>
using namespace std;

// cách 1: chaining
class HashTableChaining {
    int size;
    list<int>* table;
public:
    HashTableChaining(int s) {
        size = s;
        table = new list<int>[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool searchItem(int key) {
        int index = hashFunction(key);
        for (auto x : table[index])
            if (x == key) return true;
        return false;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }

    ~HashTableChaining() {
        delete[] table;
    }
};

// cách 2: linear
class HashTableLinear {
    int* table;
    int size;
    int EMPTY, DELETED;
public:
    HashTableLinear(int s) {
        size = s;
        table = new int[size];
        EMPTY = -1;
        DELETED = -2;
        for (int i = 0; i < size; i++) table[i] = EMPTY;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        int start = index;
        do {
            if (table[index] == EMPTY || table[index] == DELETED) {
                table[index] = key;
                return;
            }
            index = (index + 1) % size;
        } while (index != start);
        cout << "Hash table is full, cannot insert" << key << endl;
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        int start = index;
        do {
            if (table[index] == EMPTY) return;
            if (table[index] == key) {
                table[index] = DELETED;
                return;
            }
            index = (index + 1) % size;
        } while (index != start);
    }

    bool searchItem(int key) {
        int index = hashFunction(key);
        int start = index;
        do {
            if (table[index] == EMPTY) return false;
            if (table[index] == key) return true;
            index = (index + 1) % size;
        } while (index != start);
        return false;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            if (table[i] == EMPTY)
                cout << i << " : [ ]" << endl;
            else if (table[i] == DELETED)
                cout << i << " : [x]" << endl;
            else
                cout << i << " : " << table[i] << endl;
        }
    }

    ~HashTableLinear() {
        delete[] table;
    }
};


int main() {
    cout << "chainings\n";
    HashTableChaining hc(7);
    int keys1[] = {15, 11, 27, 8, 12, 7, 14};
    for (int k : keys1) hc.insertItem(k);
    hc.displayHash();
    cout << "Xoa 12\n";
    hc.deleteItem(12);
    hc.displayHash();
    cout << "Tim 27: " << (hc.searchItem(27) ? "Co" : "Khong") << endl;
    cout << "Tim 100: " << (hc.searchItem(100) ? "Co" : "Khong") << endl;

    cout << "\nlinear:\n";
    HashTableLinear hl(7);
    int keys2[] = {15, 11, 27, 8, 12, 7, 14};
    for (int k : keys2) hl.insertItem(k);
    hl.displayHash();
    cout << "Xoa 12\n";
    hl.deleteItem(12);
    hl.displayHash();
    cout << "Tim 27: " << (hl.searchItem(27) ? "Co" : "Khong") << endl;
    cout << "Tim 100: " << (hl.searchItem(100) ? "Co" : "Khong") << endl;

    return 0;
}
