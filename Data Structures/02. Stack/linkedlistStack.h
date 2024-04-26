#ifndef _LINKEDLISTSTACK_H
#define _LINKEDLISTSTACK_H

#include "singleLinkedList.h"


template <class Type>
class linkedStackType {
private:
    node<Type>* stackTop;
    int count = 0;

public:
    // Default constructor
    linkedStackType();

    // Copy constructor
    linkedStackType(const linkedStackType<Type>& otherStack);

    // Destructor
    ~linkedStackType();

    // Assignment operator overload
    linkedStackType<Type>& operator=(const linkedStackType<Type>& otherStack);


    // Push element onto the stack
    void push(const Type& element);

    // Pop element from the stack
    Type pop();

    // Return the top element without removing it
    Type top() const;

    // Check if the stack is empty
    bool isEmpty() const;

    // Return the size of the stack
    int stackSize() const;

    // Clear the stack
    void clear();

    // Print the stack
    void print() const;



};

template <class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = nullptr;
}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack) {
    // Initialize stackTop and count
    stackTop = nullptr;
    count = 0;

    // If other stack is not empty, copy its elements
    if (!otherStack.isEmpty()) {
        // Create a pointer to traverse other stack
        node<Type>* otherPtr = otherStack.stackTop;

        // Pointer to the last node created in the new stack
        node<Type>* lastNode = nullptr;

        // Copy the first node
        stackTop = new node<Type>;
        stackTop->info = otherPtr->info;
        lastNode = stackTop;
        count++;

        // Move to the next node in other stack
        otherPtr = otherPtr->link;

        // Copy remaining nodes
        while (otherPtr != nullptr) {
            // Create a new node with the data from other stack
            node<Type>* newNode = new node<Type>;
            newNode->info = otherPtr->info;

            // Link the last node to the new node
            lastNode->link = newNode;

            // Update lastNode to the new node
            lastNode = newNode;

            // Move to the next node in other stack
            otherPtr = otherPtr->link;

            // Increment count
            count++;
        }
    }
}

template <class Type>
linkedStackType<Type>::~linkedStackType() {
    clear();
}

template <class Type>
linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack) {

    if (this != &otherStack) {

        clear();


        if (otherStack.isEmpty()) {
            stackTop = nullptr;
            count = 0;
        } else {
            node<Type>* otherPtr = otherStack.stackTop;
            node<Type>* temp = new node<Type>;
            temp->info = otherPtr->info;
            stackTop = temp;
            otherPtr = otherPtr->link;
            count = 1;

            while (otherPtr != nullptr) {
                temp->link = new node<Type>;
                temp->info = otherPtr->info;
                temp = temp->link;
                otherPtr = otherPtr->link;
                count++;
            }
        }
    }
    return *this;
}




template <class Type>
void linkedStackType<Type>::push(const Type& element) {
    node<Type>* newNode = new node<Type>;
    newNode->info = element;
    newNode->link = stackTop;
    stackTop = newNode;
    count++;
}

template <class Type>
Type linkedStackType<Type>::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow: Cannot pop from an empty stack." << '\n';
    }
    Type poppedElement = stackTop->info;
    node<Type>* temp = stackTop;
    stackTop = stackTop->link;
    delete temp;
    count--;
    return poppedElement;
}

template <class Type>
Type linkedStackType<Type>::top() const {
    if (isEmpty()) {
        std::cerr <<"Stack is empty."<< '\n';
    }
    return stackTop->info;
}

template <class Type>
bool linkedStackType<Type>::isEmpty() const {
    return stackTop == nullptr;
}

template <class Type>
int linkedStackType<Type>::stackSize() const {
    return count;
}

template <class Type>
void linkedStackType<Type>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template <class Type>
void linkedStackType<Type>::print() const {
    node<Type>* current = stackTop;
    while (current != nullptr) {
        std::cout << current->info << " ";
        current = current->link;
    }
    std::cout << std::endl;
}







#endif //_LINKEDLISTSTACK_H
