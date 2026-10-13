#ifndef ACTION_RECORD_H
#define ACTION_RECORD_H

#include "resource.h"

enum ActionType { 
    ADD_RESOURCE, 
    DELETE_RESOURCE,
    UPDATE_RESOURCE, 
    CANCEL_BOOKING 
};

struct Action {
    ActionType type;    
    Resource before;   // snapshot needed to reverse the action(used for DELETE and UPDATE actions)
    Resource after;     // snapshot after the action (used for ADD and UPDATE actions)
    int position; // position in the resource list for undoing add/delete actions
};

#endif