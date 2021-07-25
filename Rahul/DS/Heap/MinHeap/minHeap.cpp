#include <iostream>
#include <climits>

using namespace std;

class MinHeap {
    int size;
    int arr[10000];

    int left(int i) { return 2*i+1; }
    int right(int i) {return 2*i + 2;}
    int parent(int i) {return (i-1)/2;}

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int mn = i;
        if (l < size && arr[l] < arr[i]) mn = l;
        else if (r < size && arr[r] < arr[mn]) mn = r;

        if (mn != i) {
            swap(arr[i], arr[mn]);
            minHeapify(mn);
        }
    }

public:
    MinHeap() {
        size = 0;
    }

    int getTop() {
        if (size) return arr[0];
    }

    int getSize() {
        return size;
    }

    void push(int n) {
        if (size==10000) {
            cout << "Capacity reached\n";
            return;
        }

        size++;
        int i = size-1;
        arr[i] = n;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int n) {
        if (i >= size) {
            cout << "index error" << endl;
        }
        arr[i] = n;
        while (i != 0 && arr[parent(i)] >  arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void pop() {
        if (size <= 0) {
            cout << "No elemenst to delete\n";
            return;
        }

        if (size == 1) size--;

        arr[0] = arr[size-1];
        size--;
        minHeapify(0);
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        pop();
    }

};

int main(void) {

}