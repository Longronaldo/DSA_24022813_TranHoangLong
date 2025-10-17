#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftIdx = left(index);
        int rightIdx = right(index);

        if (leftIdx < heap.size() && heap[leftIdx] > heap[largest])
            largest = leftIdx;
        if (rightIdx < heap.size() && heap[rightIdx] > heap[largest])
            largest = rightIdx;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int delMax() {
        if (isEmpty())
            throw out_of_range("Priority queue is empty");

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    int max() {
        if (isEmpty())
            throw out_of_range("Priority queue is empty");
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(50);
    pq.insert(20);
    pq.insert(70);
    pq.insert(40);

    cout << "Max: " << pq.max() << endl;       
    cout << "Deleted Max: " << pq.delMax() << endl;
    cout << "New Max: " << pq.max() << endl;
    cout << "Size: " << pq.size() << endl;
    cout << "Is Empty: " << pq.isEmpty() << endl; 
}
