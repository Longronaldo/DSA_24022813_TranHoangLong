#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {12, 11, 13, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    bubbleSort(arr1, n1);
    cout << "Bubble Sorted array: ";
    printArray(arr1, n1);

    selectionSort(arr2, n2);
    cout << "Selection Sorted array: ";
    printArray(arr2, n2);

    insertionSort(arr3, n3);
    cout << "Insertion Sorted array: ";
    printArray(arr3, n3);

    return 0;
}
