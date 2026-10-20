
#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

enum RequestStatus {
    PENDING,
    APPROVED,
    REJECTED,
    CANCELLED
};

class Request {
private:
    int requestID;
    int userID;
    int resourceID;
    string resourceType;
    string requestDate;
    int priority;
    RequestStatus status;

public:
    // Constructors
    Request();

    Request(int rid, int uid, int resid,
            string type, string date,
            int p, RequestStatus s = PENDING);

    // Getters
    int getRequestID() const;
    int getUserID() const;
    int getResourceID() const;
    string getResourceType() const;
    string getRequestDate() const;
    int getPriority() const;
    RequestStatus getStatus() const;

    // Setters
    void setRequestID(int rid);
    void setUserID(int uid);
    void setResourceID(int resid);
    void setResourceType(string type);
    void setRequestDate(string date);
    void setPriority(int p);
    void setStatus(RequestStatus s);

    // Display
    string statusToString() const;
    void display() const;

    // MinHeap comparison
    bool operator<(const Request& other) const;
};

#endif
