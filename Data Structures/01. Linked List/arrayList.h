#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include <iostream>


template<class Type, int maxSize>
class ArrayList {
private:
    Type elements[maxSize]; // Array to store elements
    int count; // Variable to store the number of elements in the list

public:
    // Default Constructor O(1)
    ArrayList();

    // Copy constructor
    ArrayList(const ArrayList<Type, maxSize>& otherList);

    // Destructor
    ~ArrayList();

    // Function to make a copy of otherList
    void copyList(const ArrayList<Type, maxSize>& otherList);

    // Overload assignment operator
    const ArrayList<Type, maxSize>& operator=(const ArrayList<Type, maxSize>& otherList);

    // Function to determine whether the list is empty O(1)
    bool isEmpty() const;

    // Function to output the data contained in each node
    void print() const;

    // Function to return the number of elements in the list
    int size() const;

    // Function to return the first element of the list
    Type front() const;

    // Function to return the last element of the list
    Type back() const;

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

template<class Type, int maxSize>
ArrayList<Type, maxSize>::ArrayList() : count(0) {}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::copyList(const ArrayList<Type, maxSize>& otherList) {
    count = otherList.count;
    for (int i = 0; i < count; ++i) {
        elements[i] = otherList.elements[i];
    }
}

template<class Type, int maxSize>
ArrayList<Type, maxSize>::ArrayList(const ArrayList<Type, maxSize>& otherList) {
    this->copyList(otherList);
}

template<class Type, int maxSize>
ArrayList<Type, maxSize>::~ArrayList() {}


template<class Type, int maxSize>
const ArrayList<Type, maxSize>& ArrayList<Type, maxSize>::operator=(const ArrayList<Type, maxSize>& otherList) {
    if (this != &otherList) {
        copyList(otherList);
    }
    return *this;
}

template<class Type, int maxSize>
bool ArrayList<Type, maxSize>::isEmpty() const {
    return count == 0;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::print() const {
    for (int i = 0; i < count; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

template<class Type, int maxSize>
int ArrayList<Type, maxSize>::size() const {
    return count;
}

template<class Type, int maxSize>
Type ArrayList<Type, maxSize>::front() const {
    if (isEmpty()) {
        std::cerr <<"List is empty. Cannot access front element."<< '\n';
    }
    return elements[0];
}

template<class Type, int maxSize>
Type ArrayList<Type, maxSize>::back() const {
    if (isEmpty()) {
        std::cerr <<"List is empty. Cannot access back element."<< '\n';
    }
    return elements[count - 1];
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::insertAtHead(const Type &element) {
    if (count == maxSize) {
        std::cerr <<"List is full. Cannot insert more elements."<< '\n';
    }
    for (int i = count; i > 0; --i) {
        elements[i] = elements[i - 1];
    }
    elements[0] = element;
    count++;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::insertAtTail(const Type &element) {
    if (count == maxSize) {
        std::cerr <<"List is full. Cannot insert more elements."<< '\n';
    }
    elements[count++] = element;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::insertAt(const Type &element, int index) {
    if (index < 0 || index > count) {
        std::cerr <<"Index out of bounds. Cannot insert element."<< '\n';
    }
    if (count == maxSize) {
        std::cerr <<"List is full. Cannot insert more elements."<< '\n';
    }
    for (int i = count; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = element;
    count++;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::removeAtHead() {
    if (isEmpty()) {
        std::cerr <<"List is empty. No element to remove from head."<< '\n';
    }
    for (int i = 0; i < count - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    count--;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::removeAtTail() {
    if (isEmpty()) {
        std::cerr <<"List is empty. No element to remove from tail."<< '\n';
    }
    count--;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::removeAt(int index) {
    if (index < 0 || index >= count) {
        std::cerr <<"Index out of bounds. Cannot remove element."<< '\n';
    }
    for (int i = index; i < count - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    count--;
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || secondItemIdx < 0 || firstItemIdx >= count || secondItemIdx >= count) {
        std::cerr << "Index out of bounds. Cannot perform swap."<< '\n';
    }
    Type temp = elements[firstItemIdx];
    elements[firstItemIdx] = elements[secondItemIdx];
    elements[secondItemIdx] = temp;
}

template<class Type, int maxSize>
Type ArrayList<Type, maxSize>::retrieveAt(int index) const {
    if (index < 0 || index >= count) {
        std::cerr <<"Index out of bounds. Cannot retrieve element."<< '\n';
    }
    return elements[index];
}

template<class Type, int maxSize>
void ArrayList<Type, maxSize>::replaceAt(const Type &newElement, int index) {
    if (index < 0 || index >= count) {
        std::cerr <<"Index out of bounds. Cannot replace element."<< '\n';
    }
    elements[index] = newElement;
}

template<class Type, int maxSize>
bool ArrayList<Type, maxSize>::isExist(const Type &element) const {
    for (int i = 0; i < count; ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

template<class Type, int maxSize>
bool ArrayList<Type, maxSize>::isItemAtEqual(const Type &element, int index) const {
    if (index < 0 || index >= count) {
         std::cerr<<"Index out of bounds. Cannot compare element." << '\n';
    }
    return (elements[index] == element);
}









#endif //_ARRAYLIST_H
