#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include "nodeType.h"
#include "linkedListIterators.h"
#include <iostream>
#include <cassert>


template <class Type>
class doubleLinkedList {
private:
    int count; // Variable to store the number of list elements
    dNode<Type> *first; // Pointer to the first node of the list
    dNode<Type> *last; // Pointer to the last node of the list

public:

    // Default Constructor
    doubleLinkedList();

    // Copy constructor
    doubleLinkedList(const doubleLinkedList<Type>& otherList);

    // Destructor
    ~doubleLinkedList();

    // Function to make a copy of otherList
    void copyList(const doubleLinkedList<Type>& otherList);

    // Overload assignment operator
    const doubleLinkedList<Type>& operator=(const doubleLinkedList<Type>& otherList);

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
    dLinkedListIterator<Type> begin();

    // Function to return an iterator one element past the last element of the linked list
    dLinkedListIterator<Type> end();

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
    void swap(int firstItemIdx, int secondItemIdx);

    // Function to retrieve an element
    Type retrieveAt(int index) const;

    // Function to replace an element
    void replaceAt(const Type &newElement, int index);

    // Function to check if an element exists in the list
    bool isExist(const Type &element) const;

    // Function to check if an element at a specific index is equal to a given element
    bool isItemAtEqual(const Type &element, int index) const;
};



template <class Type>
bool doubleLinkedList<Type>::isEmpty() const {
    return (first == nullptr);
}

template <class Type>
doubleLinkedList<Type>::doubleLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
int doubleLinkedList<Type>::size() const {
    return count;
}

template <class Type>
Type doubleLinkedList<Type>::front() const {
    if (first == nullptr){
        std::cerr << "Error: List is empty. Cannot access front element." << '\n';
        exit(EXIT_FAILURE);
    }
    return first->data; // return the data of the first node
}

template <class Type>
Type doubleLinkedList<Type>::back() const {
    if (last == nullptr) {
        std::cerr << "Error: List is empty. Cannot access back element." << '\n';
        exit(EXIT_FAILURE);
    }
    return last->data; // return the data of the last node
}


template <class Type>
dLinkedListIterator<Type> doubleLinkedList<Type>::begin() {
    dLinkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
dLinkedListIterator<Type> doubleLinkedList<Type>::end() {
    dLinkedListIterator<Type> temp(nullptr);
    return temp;
}

template <class Type>
void doubleLinkedList<Type>::copyList(const doubleLinkedList<Type>& otherList) {
    dNode<Type> *newNode; // pointer to create a node
    dNode<Type> *current; // pointer to traverse the list

    // If the current list is nonempty, make it empty
    if (first != nullptr)
        destroyList();

    // If otherList is empty, set current list to empty
    if (otherList.first == nullptr) {
        first = nullptr;
        last = nullptr;
        count = 0;
    } else {
        current = otherList.first; // current points to the list to be copied
        count = otherList.count;

        // Copy the first node
        first = new dNode<Type>; // create the node
        first->data = current->data; // copy the data
        first->prev = nullptr; // set the prev field of the node to nullptr
        last = first; // make last point to the first node
        current = current->next; // make current point to the next node

        // Copy the remaining list
        while (current != nullptr) {
            newNode = new dNode<Type>; // create a node
            newNode->data = current->data; // copy the data
            newNode->prev = last; // set the prev of newNode to last
            newNode->next = nullptr; // set the next of newNode to nullptr
            last->next = newNode; // attach newNode after last
            last = newNode; // make last point to the actual last node
            current = current->next; // make current point to the next node
        }
    }
}

// Copy Constructor
template <class Type>
doubleLinkedList<Type>::doubleLinkedList(const doubleLinkedList<Type>& otherList) {
    first = nullptr;
    copyList(otherList);
}

// Copy Constructor
template <class Type>
const doubleLinkedList<Type>& doubleLinkedList<Type>::operator=(const doubleLinkedList<Type>& otherList) {
    if (this != &otherList) { // avoid self-assignment
        copyList(otherList);
    }
    return *this;
}


template <class Type>
void doubleLinkedList<Type>::print() const {
    dNode<Type> *current;
    current = first;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

template <class Type>
void doubleLinkedList<Type>::destroyList() {
    dNode<Type> *temp;

    while (first != nullptr) {
        temp = first;
        first = first->next;
        delete temp;
    }

    last = nullptr;
    count = 0;
}

template <class Type>
doubleLinkedList<Type>::~doubleLinkedList() {
    destroyList();
}

template<class Type>
void doubleLinkedList<Type>::insertAtHead(const Type& newItem) {
    // Create a new node
    dNode<Type>* newNode = new dNode<Type>;
    newNode->data = newItem; // Store the new item in the node
    newNode->prev = nullptr; // Set the prev field of newNode to nullptr
    newNode->next = first; // Insert newNode before first

    // Update first to point to the new node
    if (first != nullptr)
        first->prev = newNode;
    first = newNode; // Make first point to the actual first node

    // Update last if the list was empty
    if (last == nullptr)
        last = newNode;

    count++; // Increment count
}

template<class Type>
void doubleLinkedList<Type>::insertAtTail(const Type& newItem) {
    // Create a new node
    dNode<Type>* newNode = new dNode<Type>;
    newNode->data = newItem; // Store the new item in the node
    newNode->prev = last; // Set the prev field of newNode to last
    newNode->next = nullptr; // Set the next field of newNode to nullptr

    // If the list is empty, newNode is both the first and last node
    if (first == nullptr) {
        first = newNode;
        last = newNode;
    } else {
        // The list is not empty, insert newNode after last
        last->next = newNode; // Insert newNode after last
        last = newNode; // Make last point to the actual last node in the list
    }

    count++; // Increment count
}

template<class Type>
void doubleLinkedList<Type>::insertAt(const Type& element, int index) {
    if (index < 0 || index > size()) {
        std::cerr << "Index out of bounds" << '\n';
        return;
    }
    if (index == 0) {
        insertAtHead(element);
    } else if (index == size()) {
        insertAtTail(element);
    } else {
        dNode<Type> *newNode = new dNode<Type>;
        newNode->data = element;
        dNode<Type> *prev = nullptr;
        dNode<Type> *current = first;
        for (int i = 0; i < index ; ++i) {
            prev = current;
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = prev;
        prev->next = newNode;
        current->prev = newNode;
        count++;
    }
}

template<class Type>
void doubleLinkedList<Type>::removeAtHead() {
    if (first == nullptr) {
        std::cerr << "List is empty. No element to remove from head." << '\n';
        return;
    }

    dNode<Type>* temp = first;
    first = first->next;
    if (first != nullptr)
        first->prev = nullptr;
    delete temp;
    count--;
}

template<class Type>
void doubleLinkedList<Type>::removeAtTail() {
    if (first == nullptr) {
        std::cerr << "List is empty. No element to remove from tail." << '\n';
        return;
    }

    if (first->next == nullptr) { // Only one node in the list
        delete first;
        first = last = nullptr;
        count = 0;
        return;
    }

    dNode<Type>* temp = last;
    last = last->prev;
    last->next = nullptr;
    delete temp;
    count--;
}

template<class Type>
void doubleLinkedList<Type>::removeAt(int index) {
    if (index < 0 || index >= size()) {
        std::cerr << "Index out of bounds. Cannot remove element." << '\n';
        return;
    }

    if (index == 0) { // Removing the head
        removeAtHead();
        return;
    }

    if (index == size() - 1) { // Removing the tail
        removeAtTail();
        return;
    }

    dNode<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current; // Delete the node
    count--; // Decrease the count
}

template<class Type>
void doubleLinkedList<Type>::swap(int firstItemIdx, int secondItemIdx) {
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
    dNode<Type>* curr1 = first;
    for (int i = 0; i < firstItemIdx; ++i) {
        curr1 = curr1->next;
    }

    dNode<Type>* curr2 = first;
    for (int i = 0; i < secondItemIdx; ++i) {
        curr2 = curr2->next;
    }

    // If the nodes are adjacent, just update the links
    if (curr1->next == curr2) {
        if (curr1->prev != nullptr) {
            curr1->prev->next = curr2;
        } else {
            first = curr2;
        }
        curr2->prev = curr1->prev;
        curr1->next = curr2->next;
        curr2->next = curr1;
        if (curr1->next != nullptr) {
            curr1->next->prev = curr1;
        }
        curr1->prev = curr2;
    } else {
        // Swap the nodes
        if (curr1->prev != nullptr) {
            curr1->prev->next = curr2;
        } else {
            first = curr2;
        }
        if (curr2->prev != nullptr) {
            curr2->prev->next = curr1;
        } else {
            first = curr1;
        }
        std::swap(curr1->prev, curr2->prev);
        std::swap(curr1->next, curr2->next);
        if (curr1->next != nullptr) {
            curr1->next->prev = curr1;
        }
        if (curr2->next != nullptr) {
            curr2->next->prev = curr2;
        }
    }
}


template<class Type>
Type doubleLinkedList<Type>::retrieveAt(int index) const {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot retrieve element." << std::endl;
        exit(EXIT_FAILURE);
    }

    dNode<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}


template<class Type>
void doubleLinkedList<Type>::replaceAt(const Type &newElement, int index) {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot replace element." << std::endl;
        exit(EXIT_FAILURE);
    }

    dNode<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = newElement;
}

template<class Type>
bool doubleLinkedList<Type>::isExist(const Type &element) const {
    dNode<Type>* current = first;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class Type>
bool doubleLinkedList<Type>::isItemAtEqual(const Type &element, int index) const {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot compare element." << std::endl;
        return false;
    }

    dNode<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return (current->data == element);
}







#endif //_DOUBLYLINKEDLIST_H
