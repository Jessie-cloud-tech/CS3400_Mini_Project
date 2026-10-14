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
	public:
		void insertfirst(T);
		void insertlast(T);
		void insertparticular(T,int);
		void removefirst();
		void removelast();
		void removeparticular(int);
		bool search(T); //lenear search
		void clear();
		~linkedlist();
		linkedlist();
		void display();
		
};
#include "../src/LinkedList.cpp"
#endif // LINKEDLIST_H