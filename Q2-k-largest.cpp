#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);

        heapify(heap, n, smallest);
    }

    return;
}

// Function to find the k'th largest element in an array using min-heap
int findKthLargest(vector<int> const& ints, int k)
{

    //Check if k is within range
    if (k < 0 || k > ints.size()) {
        return -1;
    }

    vector<int> minHeap;
    vector<int> list;

    //Fill heap with first k items
    for (int i = 0; i < k; i++) {
        minHeap.push_back(ints[i]);
    }

    //Put remaining items in another vector
    for (int i = k; i < ints.size(); i++) {
        list.push_back(ints[i]);
    }

    //Heapify k elements while swapping in the next item in the list if it is larger
    for (int i = 0; i < list.size(); i++) {

        for (int j = minHeap.size() - 1; j >= 0; j--) {
            heapify(minHeap, k, j);
        }

        if (list[i] > minHeap[0]) {
            swap(list[i], minHeap[0]);
        }

    }

    //Special case for if k equals the number of items in the list
    if (k == ints.size()) {
        for (int i = minHeap.size() - 1; i >= 0; i--) {
            heapify(minHeap, k, i);
        }
    }

    return minHeap[0];
}

int main()
{
    vector<int> ints = { 7, 4, 6, 3, 9, 1 };
    int k = 3;

    cout << "k'th largest array element is " << findKthLargest(ints, k);

    return 0;
}