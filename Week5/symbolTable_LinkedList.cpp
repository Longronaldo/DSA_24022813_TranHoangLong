#include <iostream>
#include <string>

using namespace std;

struct SymbolNode {
    string name;
    string type;
    SymbolNode* next;

    SymbolNode(string n, string t) : name(n), type(t), next(nullptr) {}
};

class SymbolTable {
private:
    SymbolNode* head;

public:
    SymbolTable() : head(nullptr) {}

    string find(string name) {
        SymbolNode* cur = head;
        while (cur != nullptr) {
            if (cur->name == name) return cur->type;
            cur = cur->next;
        }
        return "null";
    }

    void insert(string name, string type) {
        SymbolNode* cur = head;
        while (cur != nullptr) {
            if (cur->name == name) {
                cur->type = type;
                return;
            }
            cur = cur->next;
        }
        SymbolNode* newNode = new SymbolNode(name, type);
        newNode->next = head;
        head = newNode;
    }

    void remove(string name) {
        if (head == nullptr) return;

        if (head->name == name) {
            SymbolNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        SymbolNode* cur = head;
        while (cur->next != nullptr && cur->next->name != name)
            cur = cur->next;

        if (cur->next == nullptr) return;

        SymbolNode* toDelete = cur->next;
        cur->next = cur->next->next;
        delete toDelete;
    }

    void print() {
        SymbolNode* cur = head;
        while (cur != nullptr) {
            cout << "Name: " << cur->name << ", type: " << cur->type << endl;
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }

    ~SymbolTable() {
        SymbolNode* current = head;
        while (current != nullptr) {
            SymbolNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
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
