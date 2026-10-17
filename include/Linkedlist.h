#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "resource.h"


template <class T>

struct Node{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <class T>
class linkedlist{
	private:
		Node<T>* head;
		int count;

	public:
		void insertfirst(T);
		void insertlast(T);
		bool insertparticular(T,int);
		void removefirst();
		void removelast();
		void removeparticular(int);
		bool search(T); //lenear search
		void clear();
		~linkedlist();
		linkedlist();
		void display() const;

		//disable copy constructor and assignment operator
		linkedlist(const linkedlist&) = delete;
		linkedlist& operator=(const linkedlist&) = delete;

		//methods needed for undo stack
		bool updateByID(int id, T updated, T& before);	//update a node by ID and return the previous data in before
		bool findByID(int id, T& result) const;	//finds a node by ID and returns the data in result
		bool removeAt(int position, T& removed); //removes a node at a specific position and returns the data in removed
		int size() const; //returns the size of the linked list
		
};
#include "../src/LinkedList.cpp"
#endif // LINKEDLIST_H