
#ifndef REQUEST_MANAGER_H
#define REQUEST_MANAGER_H

#include "request.h"
#include "queue.h"
#include "min_heap.h"

class RequestManager {
private:
    Queue<Request> normalRequests;
    MinHeap priorityRequests;

public:
    // Submit requests
    void submitNormalRequest(const Request& request);
    void submitPriorityRequest(const Request& request);

    // Retrieve the next request for processing
    Request getNextNormalRequest();
    Request getNextPriorityRequest();

    // Check pending requests
    bool hasNormalRequests();
    bool hasPriorityRequests();

    // Display queue sizes
    void displayRequestCounts();
};

#endif
