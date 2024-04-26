#ifndef _LINKEDLISTITERATORS_H
#define _LINKEDLISTITERATORS_H

#include "nodeType.h"


// Linked List Iterators
template <class Type>
class linkedListIterator {
private:
    node<Type> *current;

public:
    linkedListIterator();

    linkedListIterator(node<Type> *ptr);

    Type operator*();

    linkedListIterator<Type> operator++();


    bool operator==(const linkedListIterator<Type>& right) const;


    bool operator!=(const linkedListIterator<Type>& right) const;
};


template <class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(node<Type> *ptr) {
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
    return (current != right.current);
}



// Doubly Linked List Iterators
template <class Type>
class dLinkedListIterator {
private:
    dNode<Type> *current;

public:
    dLinkedListIterator();

    dLinkedListIterator(dNode<Type> *ptr);

    Type operator*();

    dLinkedListIterator<Type>& operator++();

    bool operator==(const dLinkedListIterator<Type>& right) const;

    bool operator!=(const dLinkedListIterator<Type>& right) const;
};




template <class Type>
dLinkedListIterator<Type>::dLinkedListIterator() {
    current = nullptr;
}

template <class Type>
dLinkedListIterator<Type>::dLinkedListIterator(dNode<Type> *ptr) {
    current = ptr;
}

template <class Type>
Type dLinkedListIterator<Type>::operator*() {
    return current->data;
}

template <class Type>
dLinkedListIterator<Type>& dLinkedListIterator<Type>::operator++() {
    current = current->next;
    return *this;
}



template <class Type>
bool dLinkedListIterator<Type>::operator==(const dLinkedListIterator<Type>& right) const {
    return (current == right.current);
}

template <class Type>
bool dLinkedListIterator<Type>::operator!=(const dLinkedListIterator<Type>& right) const {
    return (current != right.current);
}























#endif // _LINKEDLISTITERATORS_H
