#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "resource.h"
#include "Linkedlist.h"
#include "stack.h"
#include "action_record.h"

class ResourceManager {
    private:
        linkedlist<Resource> resources;  //storage for resources
        Stack<Action> undo_stack;   //stack to store actions for undo functionality
    
    public:

        //storage management
        bool deleteResourceAt(int position);    //delete a resource at a specific position
        bool addResource(const Resource& resource); //add a new resource to the list
        bool updateResource(const Resource& updated); //update an existing resource in the list

        void displayResources() const; //display all resources in the list
        bool findResourceByID(int id, Resource& result) const; //find a resource by its ID and return it in result
        int getResourceCount() const; //get the number of resources in the list
        

        //undo functionality
        void recordAction(const Action& action); //record an action to the undo stack
        bool undoLastAction();  //undo the last action performed on the resource list

};

#endif // RESOURCE_MANAGER_H