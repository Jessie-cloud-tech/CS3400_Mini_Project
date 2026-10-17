#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

using std::string;

class Resource {
private:
    int resourceID;
    string name;
    string type;
    string location;
    int capacity;
    bool available;
public:
    Resource();
    Resource(int,string,string,string,int,bool);
    //setters
    void setResourceID(int);
    void setName(string);
    void setType(string);
    void setLocation(string);
    void setCapacity(int);
    void setAvailable(bool);

    // Getters
    int getResourceID() const;
    string getName() const;
    string getType() const;
    string getLocation() const;
    int getCapacity() const;
    bool isAvailable() const;
    void display() const;

    //comparison operators
    bool operator==(const Resource& other) const;
    bool operator!=(const Resource& other) const;

    //copy constructor and assignment operator
    Resource(const Resource& other);
    Resource& operator=(const Resource& other);
};


#endif // #ifnotdef