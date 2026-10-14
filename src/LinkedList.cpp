#include <iostream>
//#include "../include/LinkedList.h"
using namespace std;

//CONSTRACTOR
template <class T>
linkedlist<T>::linkedlist(){
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
		return;
	}
	Node<T>* current = head;
	
	while(current->next != nullptr){
		current =current->next;
	}
	current->next = newnode;
	newnode->prev = current;
}
// INSERT AT  GIVEN POSITION5
template <class T>
void linkedlist<T>::insertparticular(T value,int position){
	
	if(position < 0){
		return;
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
		return;
	}
	
	Node<T>* current =head;
	
	for(int i =0;i<position-1;i++){//POSITION-1 to stop before the disired position
		if(current == nullptr){ //for a position that does not exist
			delete newnode;
			return;
		}
		current =current->next;
	}
	
	if(current == nullptr){
        delete newnode;
        return;
    }

    newnode->next = current->next;
    newnode->prev = current;

    if(current->next != nullptr){
        current->next->prev = newnode;
    }

    current->next = newnode;
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
void linkedlist<T>::display(){
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
