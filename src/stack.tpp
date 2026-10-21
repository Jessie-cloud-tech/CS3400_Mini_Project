#include <iostream>
#include<stdexcept>

template<typename T>
Stack<T>::Stack() {
    top = nullptr;
    count = 0;
}

template<typename T>
Stack<T>::~Stack(){
    clear();
}

template<typename T>
void Stack<T>::push(T data) {
    StackNode<T>* newNode = createNode(data);

    newNode -> next = top;
    top = newNode;

    count++;
}


template<typename T>
T Stack<T>::pop() {
    if(top == nullptr) {
        throw std::underflow_error("Stack is empty");
    }

    StackNode<T>* temp = top;
    T value = temp-> data;

    top = temp-> next;

    delete temp;
    count--;
    return value;
}

template<typename T>
T Stack<T>::peek() 
{
    if(top == nullptr) {
        throw std::underflow_error("Stack is empty");
    }

    return top->data;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr && count == 0;
}

template<typename T>
int Stack<T>::size() {
    return count;
}

template<typename T>
void Stack<T>::clear() {
    while(!isEmpty()) {
        pop();
    }

    count = 0;
}



