#ifndef _SINGLELINKEDLIST_H
#define _SINGLELINKEDLIST_H

#include "nodeType.h"
#include "linkedListIterators.h"
#include <iostream>
#include <cassert>




template <class Type>
class singleLinkedList {

private:

protected:
    int count; // Variable to store the number of list elements
    node<Type> *first; // Pointer to the first node of the list
    node<Type> *last; // Pointer to the last node of the list


public:

    // Default Constructor O(1)
    singleLinkedList();

    // Copy constructor
    singleLinkedList(const singleLinkedList<Type>& otherList);

    // Destructor
     ~singleLinkedList();

    // Function to make a copy of otherList
    void copyList(const singleLinkedList<Type>& otherList);


    // Overload assignment operator
    const singleLinkedList<Type>& operator=(const singleLinkedList<Type>& otherList);



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
     void insertAtHead(const Type &element) ;

    // Function to insert at tail
     void insertAtTail(const Type &element) ;

    // Function to insert at an index
     void insertAt(const Type &element, int index) ;

    // Function to remove from head
     void removeAtHead() ;

    // Function to remove from tail
     void removeAtTail() ;

    // Function to remove from an index
     void removeAt(int index) ;

    // Function to swap elements
     void swap(int firstItemIdx, int secondItemIdx) ;// swap two nodes without swapping data.

    // Function to retrieve an element
    Type retrieveAt(int index) const;


    // Function to replace an element
    void replaceAt(const Type &newElement, int index);

    bool isExist(const Type &element) const;

    bool isItemAtEqual(const Type &element, int index) const;


};


template <class Type>
bool singleLinkedList<Type>::isEmpty() const {
    return (first == nullptr);
}

template <class Type>
singleLinkedList<Type>::singleLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
int singleLinkedList<Type>::size() const {
    return count;
}

template <class Type>
Type singleLinkedList<Type>::front() const {
    if (first == nullptr){
        std::cerr << "Error: List is empty. Cannot access front element." << '\n';
        exit(EXIT_FAILURE);
    }
    return first->info; // return the info of the first node
}

template <class Type>
Type singleLinkedList<Type>::back() const {
    if (last == nullptr) {
        std::cerr << "Error: List is empty. Cannot access back element." << '\n';
        exit(EXIT_FAILURE);
    }
    return last->info; // return the info of the last node
}

template <class Type>
linkedListIterator<Type> singleLinkedList<Type>::begin() {
    linkedListIterator<Type> temp(first);
    return temp;
}


// The last link points to a null pointer so we just return a nullptr
template <class Type>
linkedListIterator<Type> singleLinkedList<Type>::end() {
    linkedListIterator<Type> temp(nullptr);
    return temp;
}



// Copy Function to be used in copy constructor or = operator
template <class Type>
void singleLinkedList<Type>::copyList(const singleLinkedList<Type>& otherList) {
    node<Type> *newNode; // pointer to create a node
    node<Type> *current; // pointer to traverse the list

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
        first = new node<Type>; // create the node
        first->info = current->info; // copy the info
        first->link = nullptr; // set the link field of the node to nullptr
        last = first; // make last point to the first node
        current = current->link; // make current point to the next node

        // Copy the remaining list
        while (current != nullptr) {
            newNode = new node<Type>; // create a node
            newNode->info = current->info; // copy the info
            newNode->link = nullptr; // set the link of newNode to nullptr
            last->link = newNode; // attach newNode after last
            last = newNode; // make last point to the actual last node
            current = current->link; // make current point to the next node
        }
    }
}

// Copy Constructor
template <class Type>
singleLinkedList<Type>::singleLinkedList(const singleLinkedList<Type>& otherList) {
    first = nullptr;
    copyList(otherList);
}
// = Operator
template <class Type>
const singleLinkedList<Type>& singleLinkedList<Type>::operator=(const singleLinkedList<Type>& otherList) {
    if (this != &otherList) { // avoid self-assignment
        copyList(otherList);
    }
    return *this;
}

// Print the list
template <class Type>
void singleLinkedList<Type>::print() const {
    node<Type> *current; // pointer to traverse the list
    current = first; // set current point to the first node

    while (current != nullptr) { // while more data to print
        std::cout << current->info << " ";
        current = current->link;
    }

}

// Destroy List
template <class Type>
void singleLinkedList<Type>::destroyList() {
    node<Type> *temp; // pointer to deallocate the memory occupied by the node

    while (first != nullptr) { // while there are nodes in the list
        temp = first; // set temp to the current node
        first = first->link; // advance first to the next node
        delete temp; // deallocate the memory occupied by temp
    }

    last = nullptr; // initialize last to nullptr; first has already been set to nullptr by the while loop
    count = 0;
}

// Destructor
template <class Type>
singleLinkedList<Type>::~singleLinkedList()
{
    destroyList(); //if the list has any nodes, delete them
}


template<class Type>
void singleLinkedList<Type>::insertAtHead(const Type& newItem) {
    // Create a new node
    node<Type>* newNode = new node<Type>;
    newNode->info = newItem; // Store the new item in the node
    newNode->link = first; // Insert newNode before first
    first = newNode; // Make first point to the actual first node
    count++; // Increment count

    // Update last if the list was empty
    if (last == nullptr)
        last = newNode;
}

template<class Type>
void singleLinkedList<Type>::insertAtTail(const Type& newItem) {
    // Create a new node
    node<Type>* newNode = new node<Type>;
    newNode->info = newItem; // Store the new item in the node
    newNode->link = nullptr; // Set the link field of newNode to nullptr

    // If the list is empty, newNode is both the first and last node
    if (first == nullptr) {
        first = newNode;
        last = newNode;
        count++; // Increment count
    } else {
        // The list is not empty, insert newNode after last
        last->link = newNode; // Insert newNode after last
        last = newNode; // Make last point to the actual last node in the list
        count++; // Increment count
    }
}

template<class Type>
void singleLinkedList<Type>::insertAt(const Type& element, int index) {
    if (index < 0 || index > size()) {
        std::cerr << "Index out of bounds" << '\n';
        return;
    }
    if (index == 0) {
        insertAtHead(element);
    } else if (index == size()) {
        insertAtTail(element);
    } else {
        node<Type> *newNode = new node<Type>;
        newNode->info = element;
        node<Type> *prev = nullptr;
        node<Type> *current = first;
        for (int i = 0; i < index ; ++i) {
            prev = current;
            current = current->link;
        }
        newNode->link = current;
        prev->link = newNode;
        count++;
    }
}

template<class Type>
void singleLinkedList<Type>::removeAtHead() {
    if (first == nullptr) {
        std::cerr << "List is empty. No element to remove from head." << '\n';
        return;
    }

    node<Type>* temp = first;
    first = first->link;
    delete temp;
    count--;
}

template<class Type>
void singleLinkedList<Type>::removeAtTail() {
    if (first == nullptr) {
        std::cerr << "List is empty. No element to remove from tail." << '\n';
        return;
    }

    if (first->link == nullptr) { // Only one node in the list
        delete first;
        first = last = nullptr;
        count = 0;
        return;
    }

    node<Type>* current = first;
    while (current->link != last) { // Traverse till the second last node
        current = current->link;
    }
    delete last;
    last = current;
    last->link = nullptr;
    count--;
}

template<class Type>
void singleLinkedList<Type>::removeAt(int index) {
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

    node<Type>* prev = nullptr;
    node<Type>* current = first;

    for (int i = 0; i < index; ++i) {
        prev = current;
        current = current->link;
    }

    prev->link = current->link;
    delete current; // Delete the node
    count--; // Decrease the count
}

template<class Type>
void singleLinkedList<Type>::swap(int firstItemIdx, int secondItemIdx) {
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
    node<Type>* curr1 = first;
    for (int i = 0; i < firstItemIdx; ++i) {
        prev1 = curr1;
        curr1 = curr1->link;
    }

    node<Type>* prev2 = nullptr;
    node<Type>* curr2 = first;
    for (int i = 0; i < secondItemIdx; ++i) {
        prev2 = curr2;
        curr2 = curr2->link;
    }

    // If the nodes are adjacent, just update the links
    if (curr1->link == curr2) {
        if (prev1 != nullptr) {
            prev1->link = curr2;
        } else {
            first = curr2;
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
            first = curr2;
        }
        if (prev2 != nullptr) {
            prev2->link = curr1;
        } else {
            first = curr1;
        }
        node<Type>* temp = curr2->link;
        curr2->link = curr1->link;
        curr1->link = temp;
    }
}

template<class Type>
Type singleLinkedList<Type>::retrieveAt(int index) const {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot retrieve element." << std::endl;
        exit(EXIT_FAILURE);
    }

    node<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->link;
    }
    return current->info;
}

template<class Type>
void singleLinkedList<Type>::replaceAt(const Type &newElement, int index) {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot replace element." << std::endl;
        exit(EXIT_FAILURE);
    }

    node<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->link;
    }
    current->info = newElement;
}

template<class Type>
bool singleLinkedList<Type>::isExist(const Type &element) const {
    node<Type>* current = first;
    while (current != nullptr) {
        if (current->info == element) {
            return true;
        }
        current = current->link;
    }
    return false;
}


template<class Type>
bool singleLinkedList<Type>::isItemAtEqual(const Type &element, int index) const {
    if (index < 0 || index >= size()) {
        std::cerr << "Error: Index out of bounds. Cannot compare element." << std::endl;
        return false;
    }

    node<Type>* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->link;
    }
    return (current->info == element);
}





#endif //_SINGLELINKEDLIST_H
