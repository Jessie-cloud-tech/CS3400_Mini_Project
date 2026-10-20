
#include "request_manager.h"
#include <iostream>
#include <stdexcept>

using std::underflow_error;
using std::cout;
using std::endl;

// Submit a normal request
void RequestManager::submitNormalRequest(const Request& request) {

    normalRequests.enqueue(request);

    cout << "Normal request submitted successfully.\n";
}

// Submit a priority request
void RequestManager::submitPriorityRequest(
    const Request& request) {

    priorityRequests.insert(request);

    cout << "Priority request submitted successfully.\n";
}

// Retrieve the oldest normal request
Request RequestManager::getNextNormalRequest() {
    if (normalRequests.isEmpty()) {
        throw underflow_error("No normal requests available.");
    }

    return normalRequests.dequeue();
}

// Retrieve the highest-priority request
Request RequestManager::getNextPriorityRequest() {
    if (priorityRequests.isEmpty()) {
        throw underflow_error("No priority requests available.");
    }

    return priorityRequests.extractMin();
}

// Check normal queue
bool RequestManager::hasNormalRequests() {
    return !normalRequests.isEmpty();
}

// Check priority queue
bool RequestManager::hasPriorityRequests() {
    return !priorityRequests.isEmpty();
}

// Display request counts
void RequestManager::displayRequestCounts() {
    cout << "Normal requests: "<< normalRequests.size() << endl;

    cout << "Priority requests: " << priorityRequests.size() << endl;
}
