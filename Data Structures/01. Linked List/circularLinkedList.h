#ifndef _CIRCULARLINKEDLIST_H
#define _CIRCULARLINKEDLIST_H

#include "nodeType.h"
#include "linkedListIterators.h"
#include <iostream>
#include <cassert>



template <class Type>
class circularLinkedList {
private:
    int count;           // Variable to store the number of list elements
    node<Type> *head;    // Pointer to the head node of the list

public:
    // Default Constructor O(1)
    circularLinkedList();

    // Copy constructor
    circularLinkedList(const circularLinkedList<Type>& otherList);

    // Destructor
    ~circularLinkedList();

    // Function to make a copy of otherList
    void copyList(const circularLinkedList<Type>& otherList);

    // Overload assignment operator
    const circularLinkedList<Type>& operator=(const circularLinkedList<Type>& otherList);

    // Function to determine whether the list is empty O(1)
    bool isEmpty() const;

    // Function to output the data contained in each node
    void print() const;

    // Function to return the number of nodes in the list
    int size() const;

    // Function to delete all the nodes from the list
    void destroyList();

    // Function to return the first element of the list
    Type front() const;

    // Function to return the last element of the list
    Type back() const;

    // Function to return an iterator at the beginning of the linked list
    linkedListIterator<Type> begin();

    // Function to return an iterator one element past the last element of the linked list
    linkedListIterator<Type> end();

    // Function to insert at head
    void insertAtHead(const Type &element);

    // Function to insert at tail
    void insertAtTail(const Type &element);

    // Function to insert at an index
    void insertAt(const Type &element, int index);

    // Function to remove from head
    void removeAtHead();

    // Function to remove from tail
    void removeAtTail();

    // Function to remove from an index
    void removeAt(int index);

    // Function to swap elements
    void swap(int firstItemIdx, int secondItemIdx);  // swap two nodes without swapping data.

    // Function to retrieve an element
    Type retrieveAt(int index) const;

    // Function to replace an element
    void replaceAt(const Type &newElement, int index);

    // Function to check if an element exists in the list
    bool isExist(const Type &element) const;

    // Function to check if an element at a specific index is equal to a given value
    bool isItemAtEqual(const Type &element, int index) const;
};

template <class Type>
bool circularLinkedList<Type>::isEmpty() const {
    return (head == nullptr);
}

template <class Type>
circularLinkedList<Type>::circularLinkedList() {
    head = nullptr;
    count = 0;
}

template <class Type>
int circularLinkedList<Type>::size() const {
    return count;
}

template <class Type>
Type circularLinkedList<Type>::front() const {
    if (isEmpty()) {
        std::cerr << "Error: List is empty. Cannot access front element." << '\n';
        exit(EXIT_FAILURE);
    }
    return head->info;
}

template <class Type>
Type circularLinkedList<Type>::back() const {
    this->front();
}


template <class Type>
linkedListIterator<Type> circularLinkedList<Type>::begin() {
    linkedListIterator<Type> temp(head);
    return temp;
}

template <class Type>
linkedListIterator<Type> circularLinkedList<Type>::end() {
    this->begin();
}




template <class Type>
void circularLinkedList<Type>::copyList(const circularLinkedList<Type>& otherList) {
    node<Type> *newNode; // pointer to create a node
    node<Type> *current; // pointer to traverse the list
    node<Type> *prev = nullptr; // pointer to the previous node

    // If the current list is nonempty, make it empty
    if (head != nullptr)
        destroyList();

    // If otherList is empty, set current list to empty
    if (otherList.head == nullptr) {
        head = nullptr;
        count = 0;
    } else {
        current = otherList.head; // current points to the list to be copied
        count = otherList.count;

        // Copy the first node
        head = new node<Type>; // create the node
        head->info = current->info; // copy the info
        head->link = head; // set the link field of the node to itself
        prev = head; // update prev to the first node
        current = current->link; // make current point to the next node

        // Copy the remaining list
        while (current != otherList.head) {
            newNode = new node<Type>; // create a node
            newNode->info = current->info; // copy the info
            prev->link = newNode; // update the link of the previous node
            newNode->link = head; // set the link of newNode to head
            prev = newNode; // update prev to the newly created node
            current = current->link; // make current point to the next node
        }
    }
}

// Copy Constructor
template <class Type>
circularLinkedList<Type>::circularLinkedList(const circularLinkedList<Type>& otherList) {
    head = nullptr;
    copyList(otherList);
}

// Assignment Operator
template <class Type>
const circularLinkedList<Type>& circularLinkedList<Type>::operator=(const circularLinkedList<Type>& otherList) {
    if (this != &otherList) { // avoid self-assignment
        copyList(otherList);
    }
    return *this;
}


template <class Type>
void circularLinkedList<Type>::print() const {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    node<Type> *current = head; // Start at the head node

    do {
        std::cout << current->info << " "; // Print the current node's data
        current = current->link; // Move to the next node
    } while (current != head); // Stop when we reach the head node again

    std::cout << std::endl;
}


template <class Type>
void circularLinkedList<Type>::destroyList() {
    if (head == nullptr) {
        return; // List is already empty
    }

    node<Type> *current = head; // Start at the head
    node<Type> *temp; // Pointer to deallocate the memory occupied by the node

    // Iterate through the list and deallocate memory for each node
    do {
        temp = current; // Set temp to the current node
        current = current->link; // Move to the next node
        delete temp; // Deallocate memory for the current node
    } while (current != head); // Stop when we reach the head again

    head = nullptr; // Set head to nullptr to indicate an empty list
    count = 0; // Reset the count
}

// Destructor
template <class Type>
circularLinkedList<Type>::~circularLinkedList() {
    destroyList(); // Destroy the list by deallocating memory for each node
}

template<class Type>
void circularLinkedList<Type>::insertAtHead(const Type& newItem) {
    // Create a new node
    node<Type>* newNode = new node<Type>;
    newNode->info = newItem; // Store the new item in the node

    if (head == nullptr) { // List is empty
        newNode->link = newNode; // Point to itself
        head = newNode; // newNode becomes head
    } else {
        newNode->link = head; // Insert newNode before head
        node<Type>* lastNode = head;
        while (lastNode->link != head) {
            lastNode = lastNode->link; // Find the last node
        }
        lastNode->link = newNode; // Update last node's link to newNode
        head = newNode; // Update head
    }

    count++; // Increment count
}

template<class Type>
void circularLinkedList<Type>::insertAtTail(const Type& newItem) {

    // Tail is also insert at head
    this->insertAtHead(newItem);
}

template<class Type>
void circularLinkedList<Type>::insertAt(const Type& element, int index) {
    if (index < 0 || index > size()) {
        std::cerr << "Index out of bounds" << '\n';
        return;
    }

    if (index == 0) { // Insert at head
        insertAtHead(element);
        return;
    }

    // Traverse the list until the node before the desired index
    node<Type>* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->link;
    }

    // Create a new node
    node<Type>* newNode = new node<Type>;
    newNode->info = element; // Store the new item in the node
    newNode->link = current->link; // Insert newNode between current and current->link
    current->link = newNode;

    count++; // Increment count
}

template<class Type>
void circularLinkedList<Type>::removeAtHead() {
    if (head == nullptr) {
        std::cerr << "List is empty. No element to remove from head." << '\n';
        return;
    }

    if (head->link == head) { // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        node<Type>* temp = head;
        node<Type>* lastNode = head;
        while (lastNode->link != head) {
            lastNode = lastNode->link; // Find the last node
        }
        head = head->link; // Update head
        lastNode->link = head; // Update last node's link to head
        delete temp;
    }

    count--; // Decrement count
}

template<class Type>
void circularLinkedList<Type>::removeAtTail() {

    this->removeAtHead();

}


template<class Type>
void circularLinkedList<Type>::removeAt(int index) {
    if (index < 0 || index >= size()) {
        std::cerr << "Index out of bounds. Cannot remove element." << '\n';
        return;
    }

    if (index == 0) { // Removing the head
        removeAtHead();
        return;
    }

    // Traverse the list until the node before the desired index
    node<Type>* prev = nullptr;
    node<Type>* current = head;
    for (int i = 0; i < index; ++i) {
        prev = current;
        current = current->link;
    }

    prev->link = current->link; // Update link of previous node
    delete current; // Delete the node
    count--; // Decrement count
}

template<class Type>
void circularLinkedList<Type>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || secondItemIdx < 0 || firstItemIdx >= size() || secondItemIdx >= size()) {
        std::cerr << "Index out of bounds. Cannot perform swap." << '\n';
        return;
    }

    if (firstItemIdx == secondItemIdx) { // No need to swap
        return;
    }

    // Ensure firstItemIdx is smaller than secondItemIdx
    if (firstItemIdx > secondItemIdx) {
        std::swap(firstItemIdx, secondItemIdx);
    }

    // Find the nodes to be swapped
    node<Type>* prev1 = nullptr;
    node<Type>* curr1 = head;
    for (int i = 0; i < firstItemIdx; ++i) {
        prev1 = curr1;
        curr1 = curr1->link;
    }

    node<Type>* prev2 = nullptr;
    node<Type>* curr2 = head;
    for (int i = 0; i < secondItemIdx; ++i) {
        prev2 = curr2;
        curr2 = curr2->link;
    }

    // If the nodes are adjacent, just update the links
    if (curr1->link == curr2) {
        if (prev1 != nullptr) {
            prev1->link = curr2;
        } else {
            head = curr2;
        }
        prev2->link = curr1;
        node<Type>* temp = curr2->link;
        curr2->link = curr1;
        curr1->link = temp;
    } else {
        // Swap the nodes
        if (prev1 != nullptr) {
            prev1->link = curr2;
        } else {
            head = curr2;
        }
        if (prev2 != nullptr) {
            prev2->link = curr1;
        } else {
            head = curr1;
        }
        node<Type>* temp = curr2->link;
        curr2->link = curr1->link;
        curr1->link = temp;
    }
}

template<class Type>
Type circularLinkedList<Type>::retrieveAt(int index) const {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot retrieve element." << std::endl;
        exit(EXIT_FAILURE);
    }

    node<Type>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->link;
    }
    return current->info;
}

template<class Type>
void circularLinkedList<Type>::replaceAt(const Type &newElement, int index) {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot replace element." << std::endl;
        exit(EXIT_FAILURE);
    }

    node<Type>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->link;
    }
    current->info = newElement;
}

template<class Type>
bool circularLinkedList<Type>::isExist(const Type &element) const {
    node<Type>* current = head;
    do {
        if (current->info == element) {
            return true;
        }
        current = current->link;
    } while (current != head); // Continue until we reach the head again
    return false;
}

template<class Type>
bool circularLinkedList<Type>::isItemAtEqual(const Type &element, int index) const {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot compare element." << std::endl;
        return false;
    }

    node<Type>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->link;
    }
    return (current->info == element);
}













#endif //_CIRCULARLINKEDLIST_H
