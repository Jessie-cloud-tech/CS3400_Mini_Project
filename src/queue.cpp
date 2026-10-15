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


template <typename T>
T Queue<T>::peek() {

    // Check if the queue is empty, if it is, throw an exception
    if(front == nullptr) {
        throw std::underflow_error("Queue is empty");
    }
    
    // Return the data of the front node without removing it
    return front->data;

}

template <typename T>
bool Queue<T>::isEmpty() {

    return front == nullptr && rear == nullptr;

}

template <typename T>
int Queue<T>::size() {

    return count;
    
}

template <typename T>
void Queue<T>::clear() {

    // Dequeue all elements from the queue until it is empty
    while(!isEmpty()) {
        dequeue();
    }

    // Reset front, rear, and count to indicate an empty queue
    front = rear = nullptr;
    count = 0;
}