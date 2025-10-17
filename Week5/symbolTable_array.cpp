#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

struct Symbol {
    string name;
    string type;
};

class SymbolTable {
private:
    Symbol table[MAX_SIZE];
    int size;

public:
    SymbolTable() : size(0) {}

    string find(string name) {
        for (int i = 0; i < size; i++) {
            if (table[i].name == name)
                return table[i].type;
        }
        return "null";
    }

    void insert(string name, string type) {
        for (int i = 0; i < size; i++) {
            if (table[i].name == name) {
                table[i].type = type;
                return;
            }
        }
        if (size < MAX_SIZE) {
            table[size].name = name;
            table[size].type = type;
            size++;
        }
    }

    void remove(string name) {
        for (int i = 0; i < size; i++) {
            if (table[i].name == name) {
                for (int j = i; j < size - 1; j++) {
                    table[j] = table[j + 1];
                }
                size--;
                return;
            }
        }
    }x

    void print() {
        for (int i = 0; i < size; i++) {
            cout << "Name: " << table[i].name << ", type: " << table[i].type << endl;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    SymbolTable table;

    table.insert("x", "int");
    table.insert("y", "float");
    table.insert("flag", "bool");

    table.print();

    table.insert("x", "double");

    table.print();

    return 0;
}
