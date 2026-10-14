#include <iostream>
#include <stdexcept>
#include "../include/queue.h"

// Queue class implementation
template <typename T>
Queue<T>::Queue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

template <typename T>
void Queue<T>::enqueue(T data) {
    Node<T>* newnode = createNode(data);

    // If the queue is empty, set both front and rear to the new node
    if(front == nullptr) {
        front = rear = newnode;
        count ++;
        return;
    }

    // Otherwise, add the new node to the end of the queue and update rear
    rear -> next  = newnode;
    rear = newnode;
    count ++;
}

template <typename T>
T Queue<T>::dequeue() {
    // Check if the queue is empty, if it is, throw an exception
    if(front == nullptr) {
        throw std::underflow_error("Queue is empty");
    }

    // Store the front node in a temporary variable and retrieve its data
    Node<T> * temp = front;
    T value = temp->data;

    // Move the front pointer to the next node in the queue
    front = temp->next;

    // If the queue becomes empty after dequeue, set rear to nullptr
    if(front == nullptr) {
        rear = nullptr;
    }

    
    delete temp;
    count--;
    return value;

}