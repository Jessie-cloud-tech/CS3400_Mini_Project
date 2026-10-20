
#include "min_heap.h"
#include <stdexcept>
#include <utility>

// Insert a request
bool MinHeap::insert(const Request& request) {
    requests.push_back(request);

    int index = static_cast<int>(requests.size()) - 1;
    heapifyUp(index);

    return true;
}

// Move an element up to restore the min-heap property
void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (!(requests[index] < requests[parent])) {
            break;
        }

        std::swap(requests[index], requests[parent]);
        index = parent;
    }
}

// Move an element down to restore the min-heap property
void MinHeap::heapifyDown(int index) {
    int n = static_cast<int>(requests.size());

    while (true) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Check the left child
        if (left < n && requests[left] < requests[smallest]) {
            smallest = left;
        }

        // Check the right child
        if (right < n &&requests[right] < requests[smallest]) {
            smallest = right;
        }

        // The heap property is satisfied
        if (smallest == index) {
            break;
        }

        std::swap(requests[index], requests[smallest]);
        index = smallest;
    }
}

// Return the smallest-priority request without removing it
Request MinHeap::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Cannot peek: MinHeap is empty.");
    }

    return requests[0];
}

// Remove and return the smallest-priority request
Request MinHeap::extractMin() {
    if (isEmpty()) {
        throw std::out_of_range(
            "Cannot extract: MinHeap is empty."
        );
    }

    Request minimum = requests[0];

    if (requests.size() == 1) {
        requests.pop_back();
        return minimum;
    }

    requests[0] = requests.back();
    requests.pop_back();

    heapifyDown(0);

    return minimum;
}

// Check whether the heap is empty
bool MinHeap::isEmpty() const {
    return requests.empty();
}

// Remove all requests
void MinHeap::clear() {
    requests.clear();
}

// Return the number of requests
int MinHeap::size() const {
    return static_cast<int>(requests.size());
}
