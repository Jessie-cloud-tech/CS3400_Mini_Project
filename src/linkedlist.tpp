#include <iostream>
//#include "../include/LinkedList.h"
using std::cout;
using std::endl;

//CONSTRACTOR
template <class T>
linkedlist<T>::linkedlist(){
	count  = 0;
	head = nullptr; //head now contains initialized address
}
//INSERTING AT THE FRONT
template <class T>
void linkedlist<T>::insertfirst(T value){
	Node<T>* newnode = new Node<T>;
	newnode->data = value;
	newnode->next = head;
	newnode->prev = nullptr;
	
	if(head != nullptr){
		head->prev = newnode;
	}

	
	head = newnode;
	count++; // Increment the count when a new node is added
	
}

//INSERTING AT THE BACK
template <class T>
void linkedlist<T>::insertlast(T value){
	Node<T>* newnode = new Node<T>;
	newnode->data = value;
	newnode->prev = nullptr; 
	newnode->next = NULL;
	if(head ==NULL){
		head = newnode;

		count++; // Increment the count when a new node is added
		return;
	}
	Node<T>* current = head;
	
	while(current->next != nullptr){
		current =current->next;
	}
	current->next = newnode;
	newnode->prev = current;

	count++; // Increment the count when a new node is added
}


// INSERT AT  GIVEN POSITION5
template <class T>
bool linkedlist<T>::insertparticular(T value,int position){
	
	if(position < 0){
		throw "Position cannot be less than 0";
	}

	Node<T>* newnode = new Node<T>;
	newnode->data = value;
	newnode->next = nullptr;
    newnode->prev = nullptr;
	
	if(position == 0){
		newnode->next=head;
		
		
        if(head != nullptr){
            head->prev = newnode;
        }

		head =newnode;

		count++; // Increment the count when a new node is added
		return true;
	}
	
	Node<T>* current =head;
	
	for(int i =0;i<position-1;i++){//POSITION-1 to stop before the disired position
		if(current == nullptr){ //for a position that does not exist
			delete newnode;
			return false;
		}
		current =current->next;
	}
	
	if(current == nullptr){
        delete newnode;
        return false;
    }

    newnode->next = current->next;
    newnode->prev = current;

    if(current->next != nullptr){
        current->next->prev = newnode;
    }

    current->next = newnode;

	count++; // Increment the count when a new node is added
	return true;
}


//REMOVING FRONT
template <class T>
void linkedlist<T>::removefirst(){
	if(head == nullptr){
		return;
	}
	Node<T>* temp =head;
	head =head->next;
	if (head != nullptr){
		head->prev = nullptr;
	}
	count--; // Decrement the count when a node is removed
	delete temp;
}


//REMOVING LAST
template <class T>
void linkedlist<T>::removelast(){
	if(head == nullptr){ //no element inthe list
		return;
	}
	if(head->next == nullptr){ // one element in the list
		delete head;
		head = nullptr;
		return;
	}
	Node<T>* current =head;
	while(current->next->next != nullptr){ //move till the second last element
		current = current-> next;
	}
	Node<T>* temp = current->next;
	current->next =nullptr;

	count--; // Decrement the count when a node is removed
	delete temp;
}


//REMOVE PARTICULAR
template <class T>
void linkedlist<T>::removeparticular(int position){
	
	if(head == nullptr || position <0){ //no element
		return;
	}
	
	if(position == 0){ //particular happens to be head
		Node<T>* temp = head;
		head = head->next;
		
		if(head != nullptr){
			head->prev = nullptr;
		}
		delete temp;

		count--; // Decrement the count when a node is removed
		return;
	}
	
	Node<T>* current = head;
	
	for(int i=0 ;i<position-1; i++){
		if(current->next == nullptr){
			return;
		}
		current =current->next;
	}
    if(current ==  nullptr|| current->next == nullptr){
        return;
    }
	Node<T>* temp =current->next;
	current->next= temp->next;
	
	if(temp->next != nullptr){
        temp->next->prev = current;
    }

	count--; // Decrement the count when a node is removed
	delete temp;
}
//SEARCH
template <class T>
bool linkedlist<T>::search(T value){
	Node<T>* current = head;
	
	while(current != nullptr){
		if(current->data == value){
			return true;
		}
		current= current->next;
	}
	return false;
}

//DISPLAY
template <class T>
void linkedlist<T>::display() const{
	Node<T>* current =head;
	
	while(current != nullptr){
		current->data.display();
		cout<<endl;
		current=current->next;
	}
	
}
// CLEAR
template <class T>
void linkedlist<T>:: clear(){
	while(head != nullptr){
		Node<T>* temp = head;
		head= head->next;
		delete temp;
	}
}
template<class T>
linkedlist<T>::~linkedlist(){
	clear();
}


//----------methods needed for undo stack--------------------
// Find a node by ID and return the data in result
template <class T>
bool linkedlist<T>::findByID(int id, T& result) const {
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data.getResourceID() == id) {
            result = current->data;
            return true;
        }

        current = current->next;
    }

    return false;
}

// Remove a node at a specific position and return the data in removed
template <class T>
bool linkedlist<T>::removeAt(int position, T& removed) {
    if (position < 0 || head == nullptr) {
        return false;
    }

    Node<T>* current = head;

    for (int i = 0; i < position; i++) {
        if (current == nullptr) {
            return false;
        }

        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    // Save the resource before deleting the node
    removed = current->data;

    // Update the previous node
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    // Update the next node
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;

	count--; // Decrement the count when a node is removed
    return true;
}


// Return the size of the linked list
template <class T>
int linkedlist<T>::size() const {
	return count;
}


// Update a node by ID and return the previous data in before 
template <class T>
bool linkedlist<T>::updateByID(int id, T updated, T& before) {
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data.getResourceID() == id) {
            before = current->data;  // Save original resource
            current->data = updated; // Replace with new version
            return true;
        }

        current = current->next;
    }

    return false; // Resource ID was not found
}