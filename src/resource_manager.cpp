#include <iostream>
#include <stdexcept>
#include "../include/resource_manager.h"

using std::cout;
using std::endl;

//delete a resource at a specific position
bool ResourceManager::deleteResourceAt(int position) {
    Resource removed;   //variable to hold the removed resource

    if(!resources.removeAt(position, removed)) {
        cout<<"Invalid position or empty list" <<endl;
        return false;
    }

    //record the action for undo functionality
    Action action;
    action.type = DELETE_RESOURCE;
    action.before = removed;
    action.position = position;

    recordAction(action); 

    cout << "Resource deleted successfully." <<endl;
    return true;
}


//record an action to the undo stack
void ResourceManager::recordAction(const Action& action) {
    undo_stack.push(action);
}


//undo the last action
bool ResourceManager::undoLastAction() {
    if(undo_stack.isEmpty()) {
        return false;
    }

    Action action = undo_stack.pop();

    switch(action.type) {
        case DELETE_RESOURCE:{
            if(resources.insertparticular(action.before, action.position)) {
                //cout << "Deleted resource restored." <<endl;
                return true;
            }

            recordAction(action);

            cout << "Deleted resource not restored.\n";
            return false;
        }

        case ADD_RESOURCE:{
            Resource removed;
            
            if(!resources.removeAt(action.position, removed)) {

                cout << "Could not undo resource addition." <<endl;
                return false;
            }

            cout << "Resource addition undone."<<endl;
            return true;    
            
        }

        case  UPDATE_RESOURCE:{

            Resource ignored;

            if(!resources.updateByID(
                action.before.getResourceID(), 
                action.before ,ignored
                )
            ){
                cout << "Could not undo resource update." <<endl;
                return false;   
            }

            cout << "Resource update undone successfully." <<endl;
            return true;


        }

        default:
            cout << "Undo for this action is not implemented."<<endl;
            return false;   
    }
}


//add a new resource to the list
bool ResourceManager::addResource(const Resource& resource)  {
    
    int position = resources.size();
    //insert at the end of the list
    resources.insertlast(resource);

    //
    Action action;
    action.type = ADD_RESOURCE;
    action.after = resource;
    action.position = position;

    recordAction(action);
   
    cout << "Resource added successfully." <<endl;
    return true;
}


void ResourceManager::displayResources(){
    resources.display();
}


bool ResourceManager::updateResource(const Resource& updated) {
    Resource old_resource;

    if(!resources.updateByID(updated.getResourceID(), updated, old_resource)) {
        cout << "Resource not found." <<endl;
        return false;
    }

    //action record
    Action action;
    action.type = UPDATE_RESOURCE;
    action.before = old_resource;
    action.after = updated;

    recordAction(action);

    cout << "Resource updated successfully." <<endl;
    return true;
}
