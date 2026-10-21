#ifndef STACK_H
#define STACK_H


template<typename T>
struct StackNode {
    T data;
    StackNode<T> * next;
};

template<typename T>
StackNode<T> * createNode(T data) {
    StackNode<T> * newNode = new StackNode<T>;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

template<typename T>
class Stack {
    private:
        StackNode<T> * top;
        int count;

    public:
        Stack(); //default constructor
        ~Stack();   //destructor

        Stack(const Stack& other) = delete; //copy constructor dissabled
        Stack& operator=(const Stack& other) = delete; //copy assignment operator dissabled

        void push(T data); //insert an element at the top of the stack
        T pop();    //return and remove the top element
        bool isEmpty(); //check if the stack is empty
        T peek();   //return the top element without removing it
        int size(); //return the number of elements in the stack
        void clear(); //clear the stack

};

#include "../src/stack.tpp"

#endif

