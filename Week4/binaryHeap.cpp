#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class BinaryHeap {
private:
    vector<int> heap;

    int parent(int k) { return k / 2; }
    int left(int k)   { return 2 * k; }
    int right(int k)  { return 2 * k + 1; }

public:
    BinaryHeap() {
        heap.push_back(0);
    }

    void insert(int data) {
        heap.push_back(data);
        swim(heap.size() - 1);
    }

    int delMax() {
        if (isEmpty()) throw out_of_range("Heap is empty");
        int maxVal = heap[1];
        swap(heap[1], heap.back());
        heap.pop_back();
        sink(1);
        return maxVal;
    }

    int max() {
        if (isEmpty()) throw out_of_range("Heap is empty");
        return heap[1];
    }

    bool isEmpty() {
        return heap.size() <= 1;
    }

    int size() {
        return heap.size() - 1;
    }

    void swim(int k) {
        while (k > 1 && heap[parent(k)] < heap[k]) {
            swap(heap[k], heap[parent(k)]);
            k = parent(k);
        }
    }

    void sink(int k) {
        int n = heap.size() - 1;
        while (left(k) <= n) {
            int j = left(k);
            if (j < n && heap[j] < heap[j + 1]) j++;
            if (heap[k] >= heap[j]) break;
            swap(heap[k], heap[j]);
            k = j;
        }
    }
};


int main() {
    BinaryHeap bh;

    bh.insert(50);
    bh.insert(20);
    bh.insert(70);
    bh.insert(30);

    cout << bh.max() << endl;
    cout << bh.delMax() << endl;
    cout << bh.max() << endl;
    cout << bh.size() << endl;
    cout << bh.isEmpty() << endl;

    return 0;
}
