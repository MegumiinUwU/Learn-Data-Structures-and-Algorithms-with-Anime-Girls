#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include <iostream>

template <typename Type, int maxSize>
class arrayStack {
private:
    int maxStackSize;
    int stackTop;
    Type *stack;

public:

    arrayStack();

    arrayStack(const arrayStack<Type, maxSize>& otherStack);

    ~arrayStack();

    void push(const Type& element);

    Type pop();

    Type top() const;

    bool isEmpty() const;

    int stackSize() const;

    void clear();

    void print() const;

    const arrayStack<Type, maxSize>& operator=(const arrayStack<Type, maxSize>& otherStack);
};


template <typename Type, int maxSize>
arrayStack<Type, maxSize>::arrayStack() {
    maxStackSize = maxSize;
    stackTop = -1;
    stack = new Type[maxStackSize];
}


template <typename Type, int maxSize>
arrayStack<Type, maxSize>::arrayStack(const arrayStack<Type, maxSize>& otherStack) {
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    stack = new Type[maxStackSize];
    for (int i = 0; i <= stackTop; ++i) {
        stack[i] = otherStack.stack[i];
    }
}

template <typename Type, int maxSize>
const arrayStack<Type, maxSize>& arrayStack<Type, maxSize>::operator=(const arrayStack<Type, maxSize>& otherStack) {
    if (this != &otherStack) {
        delete[] stack;
        maxStackSize = otherStack.maxStackSize;
        stackTop = otherStack.stackTop;
        stack = new Type[maxStackSize];
        for (int i = 0; i <= stackTop; ++i) {
            stack[i] = otherStack.stack[i];
        }
    }
    return *this;
}

template <typename Type, int maxSize>
arrayStack<Type, maxSize>::~arrayStack() {
    delete[] stack;
}



template <typename Type, int maxSize>
void arrayStack<Type, maxSize>::push(const Type& element) {
    if (stackTop == maxStackSize - 1) {
        std::cerr << "Stack Overflow! Cannot push element.\n";
        return;
    }
    stack[++stackTop] = element;
}

template <typename Type, int maxSize>
Type arrayStack<Type, maxSize>::pop() {
    if (isEmpty()) {
        std::cerr << "Stack Underflow! Cannot pop element.\n";
        exit(EXIT_FAILURE);
    }
    return stack[stackTop--];
}

template <typename Type, int maxSize>
Type arrayStack<Type, maxSize>::top() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty! Cannot retrieve top element.\n";
        exit(EXIT_FAILURE);
    }
    return stack[stackTop];
}

template <typename Type, int maxSize>
bool arrayStack<Type, maxSize>::isEmpty() const {
    return stackTop == -1;
}

template <typename Type, int maxSize>
int arrayStack<Type, maxSize>::stackSize() const {
    return stackTop + 1;
}

template <typename Type, int maxSize>
void arrayStack<Type, maxSize>::clear() {
    stackTop = -1;
}

template <typename Type, int maxSize>
void arrayStack<Type, maxSize>::print() const {
    if (isEmpty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    std::cout << "Stack: ";
    for (int i = 0; i <= stackTop; ++i) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}









#endif //_ARRAYSTACK_H
