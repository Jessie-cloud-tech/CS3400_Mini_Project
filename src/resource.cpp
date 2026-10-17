#include <iostream>
#include "../include/resource.h"
using namespace std;



Resource::Resource() {
    resourceID = 0;
    name = "";
    type = "";
    location = "";
    capacity = 0;
    available = true;
}

    // Parameterized constructor
Resource::Resource(int id, string n, string t,string loc, int cap, bool avail) {
    resourceID = id;
    name = n;
    type = t;
    location = loc;
    capacity = cap;
    available = avail;
}

// Setters
void Resource::setResourceID(int id) {
    resourceID = id;
}

void Resource::setName(string n) {
    name = n;
}

void Resource::setType(string t) {
    type = t;
}

void Resource::setLocation(string loc) {
    location = loc;
}

void Resource::setCapacity(int cap) {
    capacity = cap;
}

void Resource::setAvailable(bool avail) {
    available = avail;
}

// Getters
int Resource::getResourceID() const{
    return resourceID;
}

string Resource::getName() const{
    return name;
}

string Resource::getType() const{
    return type;
}

string Resource::getLocation() const{
    return location;
}

int Resource::getCapacity() const{
    return capacity;
}

bool Resource::isAvailable() const{
    return available;
}
void  Resource::display() const{
    cout << "Resource ID: " << resourceID << endl;
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Location: " << location << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Available: "
            << (available ? "Yes" : "No") << endl;
}


//comparison operators
bool Resource::operator==(const Resource& other) const {
    return resourceID == other.resourceID &&
           name == other.name &&
           type == other.type &&
           location == other.location &&
           capacity == other.capacity &&
           available == other.available;
}

bool Resource::operator!=(const Resource& other) const {
    return !(*this == other);
}

//copy constructor
Resource::Resource(const Resource& other) {
    resourceID = other.resourceID;
    name = other.name;
    type = other.type;
    location = other.location;
    capacity = other.capacity;
    available = other.available;
}

//assignment operator
Resource& Resource::operator=(const Resource& other) {
    if (this != &other) { // self-assignment check
        resourceID = other.resourceID;
        name = other.name;
        type = other.type;
        location = other.location;
        capacity = other.capacity;
        available = other.available;
    }
    return *this;
}