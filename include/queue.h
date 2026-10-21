#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
struct Node {
    T data;
    Node<T> * next;
};

template <typename T>
Node<T>* createNode(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

template <typename T>
class Queue {
    private:
        Node<T> * front;
        Node<T> * rear;
        int count;
    
    public:
        Queue();    //default constructor
        ~Queue();   //destructor

        Queue(const Queue& other) = delete; //copy constructor dissabled
        Queue& operator=(const Queue& other) = delete; //copy assignment operator dissabled
        
        void enqueue(T data); //insert an element at the rear of the queue
        T dequeue();  //return and remove the front element
        T peek();  //return the front element without removing it
        bool isEmpty(); //check if the queue is empty
        int size(); //return the number of elements in the queue
        void clear();   //clear the queue
};

#include "../src/queue.tpp"
#endif