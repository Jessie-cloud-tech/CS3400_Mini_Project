
#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "request.h"
#include <vector>

class MinHeap {
private:
    std::vector<Request> requests;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Insert a request into the heap
    bool insert(const Request& request);

    // Return the request with the smallest priority
    Request peek() const;

    // Remove and return the request with the smallest priority
    Request extractMin();

    // Check whether the heap is empty
    bool isEmpty() const;

    // Remove all requests
    void clear();

    // Return the number of requests
    int size() const;
};

#endif
