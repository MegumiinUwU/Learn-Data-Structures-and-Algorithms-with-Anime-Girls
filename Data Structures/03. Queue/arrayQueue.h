#ifndef _ARRAYQUEUE_H
#define _ARRAYQUEUE_H

#include <iostream>



template <class Type>
class arrayQueueType {
private:
    Type* queueArray; // Array to store the elements of the queue
    int maxSize; // Maximum size of the queue
    int front; // Index of the front element
    int rear; // Index of the rear element
    int count; // Number of elements in the queue

public:
    // Default constructor
    arrayQueueType(int size);

    // Copy constructor
    arrayQueueType(const arrayQueueType<Type>& otherQueue);

    // Destructor
    ~arrayQueueType();

    // Assignment operator overload
    arrayQueueType<Type>& operator=(const arrayQueueType<Type>& otherQueue);

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
arrayQueueType<Type>::arrayQueueType(int size) {
    if (size <= 0) {
        std::cerr << "Invalid queue size. Default size of 100 will be used." << std::endl;

    }
    maxSize = size;
    queueArray = new Type[maxSize];
    front = 0;
    rear = -1;
    count = 0;
}

template <class Type>
arrayQueueType<Type>::arrayQueueType(const arrayQueueType<Type>& otherQueue) {
    maxSize = otherQueue.maxSize;
    front = otherQueue.front;
    rear = otherQueue.rear;
    count = otherQueue.count;
    queueArray = new Type[maxSize];
    for (int i = 0; i < maxSize; ++i) {
        queueArray[i] = otherQueue.queueArray[i];
    }
}

template <class Type>
arrayQueueType<Type>::~arrayQueueType() {
    delete[] queueArray;
}

template <class Type>
arrayQueueType<Type>& arrayQueueType<Type>::operator=(const arrayQueueType<Type>& otherQueue) {
    if (this != &otherQueue) {
        delete[] queueArray;
        maxSize = otherQueue.maxSize;
        front = otherQueue.front;
        rear = otherQueue.rear;
        count = otherQueue.count;
        queueArray = new Type[maxSize];
        for (int i = 0; i < maxSize; ++i) {
            queueArray[i] = otherQueue.queueArray[i];
        }
    }
    return *this;
}

template <class Type>
void arrayQueueType<Type>::enqueue(const Type& element) {
    if (count == maxSize) {
        std::cerr << "Queue overflow: Cannot enqueue element. Queue is full." << std::endl;
        return;
    }
    rear = (rear + 1) % maxSize;
    queueArray[rear] = element;
    count++;
}

template <class Type>
Type arrayQueueType<Type>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue underflow: Cannot dequeue from an empty queue.");
    }
    Type dequeuedElement = queueArray[front];
    front = (front + 1) % maxSize;
    count--;
    return dequeuedElement;
}

template <class Type>
Type arrayQueueType<Type>::first() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return queueArray[front];
}

template <class Type>
bool arrayQueueType<Type>::isEmpty() const {
    return count == 0;
}

template <class Type>
int arrayQueueType<Type>::queueSize() const {
    return count;
}

template <class Type>
void arrayQueueType<Type>::clear() {
    front = 0;
    rear = -1;
    count = 0;
}

template <class Type>
void arrayQueueType<Type>::print() const {
    int current = front;
    while (current != rear) {
        std::cout << queueArray[current] << " ";
        current = (current + 1) % maxSize;
    }
    std::cout << queueArray[rear] << std::endl;
}













#endif //_ARRAYQUEUE_H
