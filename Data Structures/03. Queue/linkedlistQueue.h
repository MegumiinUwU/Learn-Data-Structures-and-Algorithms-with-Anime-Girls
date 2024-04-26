#ifndef _LINKEDLISTQUEUE_H
#define _LINKEDLISTQUEUE_H


#include "singleLinkedList.h"

template <class Type>
class linkedQueueType {
private:
    node<Type>* frontPtr;
    node<Type>* rearPtr;
    int count = 0;

public:
    // Default constructor
    linkedQueueType();

    // Copy constructor
    linkedQueueType(const linkedQueueType<Type>& otherQueue);

    // Destructor
    ~linkedQueueType();

    // Assignment operator overload
    linkedQueueType<Type>& operator=(const linkedQueueType<Type>& otherQueue);

    // Enqueue element into the queue
    void enqueue(const Type& element);

    // Dequeue element from the queue
    Type dequeue();

    // Return the front element without removing it
    Type first() const;

    // Check if the queue is empty
    bool isEmpty() const;

    // Return the size of the queue
    int queueSize() const;

    // Clear the queue
    void clear();

    // Print the queue
    void print() const;
};


template <class Type>
linkedQueueType<Type>::linkedQueueType() {
    frontPtr = nullptr;
    rearPtr = nullptr;
    count = 0;
}

template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) {
    // Initialize frontPtr, rearPtr, and count
    frontPtr = nullptr;
    rearPtr = nullptr;
    count = 0;

    // If other queue is not empty, copy its elements
    if (!otherQueue.isEmpty()) {
        // Create a pointer to traverse other queue
        node<Type>* otherPtr = otherQueue.frontPtr;

        // Pointer to the last node created in the new queue
        node<Type>* lastNode = nullptr;

        // Copy the first node
        frontPtr = new node<Type>;
        frontPtr->info = otherPtr->info;
        lastNode = frontPtr;
        count++;

        // Move to the next node in other queue
        otherPtr = otherPtr->link;

        // Copy remaining nodes
        while (otherPtr != nullptr) {
            // Create a new node with the data from other queue
            node<Type>* newNode = new node<Type>;
            newNode->info = otherPtr->info;

            // Link the last node to the new node
            lastNode->link = newNode;

            // Update lastNode to the new node
            lastNode = newNode;

            // Move to the next node in other queue
            otherPtr = otherPtr->link;

            // Increment count
            count++;
        }

        // Update rearPtr to point to the last node
        rearPtr = lastNode;
    }
}

template <class Type>
linkedQueueType<Type>& linkedQueueType<Type>::operator=(const linkedQueueType<Type>& otherQueue) {
    // Check for self-assignment
    if (this != &otherQueue) {
        // Clear current queue
        clear();

        // If other queue is not empty, copy its elements
        if (!otherQueue.isEmpty()) {
            // Create a pointer to traverse other queue
            node<Type>* otherPtr = otherQueue.frontPtr;

            // Pointer to the last node created in the new queue
            node<Type>* lastNode = nullptr;

            // Copy the first node
            frontPtr = new node<Type>;
            frontPtr->info = otherPtr->info;
            lastNode = frontPtr;
            count++;

            // Move to the next node in other queue
            otherPtr = otherPtr->link;

            // Copy remaining nodes
            while (otherPtr != nullptr) {
                // Create a new node with the data from other queue
                node<Type>* newNode = new node<Type>;
                newNode->info = otherPtr->info;
                // Link the last node to the new node
                lastNode->link = newNode;

                // Update lastNode to the new node
                lastNode = newNode;

                // Move to the next node in other queue
                otherPtr = otherPtr->link;

                // Increment count
                count++;
            }

            // Update rearPtr to point to the last node
            rearPtr = lastNode;
        }
    }
    return *this;
}

template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
    clear();
}

template <class Type>
void linkedQueueType<Type>::enqueue(const Type& element) {
    node<Type>* newNode = new node<Type>;
    newNode->info = element;
    if (isEmpty()) {
        frontPtr = newNode;
    } else {
        rearPtr->link = newNode;
    }
    rearPtr = newNode;
    count++;
}

template <class Type>
Type linkedQueueType<Type>::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue underflow: Cannot dequeue from an empty queue." << '\n';
    }
    Type dequeuedElement = frontPtr->info;
    node<Type>* temp = frontPtr;
    frontPtr = frontPtr->link;
    delete temp;
    count--;
    return dequeuedElement;
}

template <class Type>
Type linkedQueueType<Type>::first() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty." <<'\n';
    }
    return frontPtr->info;
}

template <class Type>
bool linkedQueueType<Type>::isEmpty() const {
    //compare frontptr to Null
    return frontPtr == nullptr;
}

template <class Type>
int linkedQueueType<Type>::queueSize() const {
    return count;
}

template <class Type>
void linkedQueueType<Type>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <class Type>
void linkedQueueType<Type>::print() const {
    node<Type>* current = frontPtr;
    while (current != nullptr) {
        std::cout << current->info << " ";
        current = current->link;
    }
    std::cout << std::endl;
}







#endif //_LINKEDLISTQUEUE_H
