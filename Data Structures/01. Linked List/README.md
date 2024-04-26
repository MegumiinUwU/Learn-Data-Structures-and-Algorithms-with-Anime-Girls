### Introduction to Anime Girls Linked Lists

In the enchanting world of data structures, imagine linked lists as the magical pathways, where each node represents a spirited anime girl, interconnected through whimsical threads of pointers. Unlike arrays, bound by rigid arrays of memory, linked lists dance freely, their nodes brimming with character and connectivity.







## Anime Girls Singly Linked List Example

### Structure
Each node in the singly linked list represents an anime girl and contains two parts:

1. **Girl's Name**: The name of the anime girl.
2. **Next Pointer**: A reference to the next anime girl in the sequence.


Sakura -> Asuna -> Rem -> Hinata -> Mikasa ->
In this example, each girl points to the next girl in the sequence, forming a singly linked list of anime girls.


<img src="[Anime Girls Images/Single Linke List.jpg](https://github.com/MegumiinUwU/Learn-Data-Structures-and-Algorithms-with-Anime-Girls/blob/main/Anime%20Girls%20Images/Single%20Linke%20List.jpg?raw=true)" alt="Single Linked List">



## Singly Linked List

A singly linked list is a linear collection of elements, where each element points to the next one in the sequence.

### Structure

A singly linked list consists of nodes, where each node contains two parts:

1. **Data**: Actual value or element stored in the node.
2. **Pointer**: Reference to the next node in the sequence. The last node's pointer is `null`.

You will find in **nodeType.h** the node type which we will use for the single linked list

### singleLinkedList Class

The `singleLinkedList` class represents a singly linked list data structure. It stores elements of type `Type` in its nodes.

#### Private Members

- **count**: An integer variable to store the number of elements in the list.
- **first**: A pointer to the first node of the list.
- **last**: A pointer to the last node of the list.

#### Public Member Functions

- **Default Constructor**: Constructs an empty linked list.
- **Copy Constructor**: Constructs a new linked list as a copy of another linked list.
- **Destructor**: Destroys the linked list, deallocating memory.
- **copyList(const singleLinkedList<Type>& otherList)**: Makes a copy of another linked list.
- **operator=**: Overloads the assignment operator to assign one linked list to another.
- **isEmpty()**: Checks if the list is empty.
- **print()**: Outputs the data contained in each node of the list.
- **size()**: Returns the number of nodes in the list.
- **destroyList()**: Deletes all nodes from the list.
- **front()**: Returns the data of the first element in the list.
- **back()**: Returns the data of the last element in the list.
- **begin()**: Returns an iterator pointing to the beginning of the list.
- **end()**: Returns an iterator pointing one element past the end of the list.
- **insertAtHead(const Type &element)**: Inserts an element at the beginning of the list.
- **insertAtTail(const Type &element)**: Inserts an element at the end of the list.
- **insertAt(const Type &element, int index)**: Inserts an element at the specified index.
- **removeAtHead()**: Removes the first element from the list.
- **removeAtTail()**: Removes the last element from the list.
- **removeAt(int index)**: Removes the element at the specified index.
- **swap(int firstItemIdx, int secondItemIdx)**: Swaps the positions of two elements in the list.
- **retrieveAt(int index)**: Retrieves the element at the specified index.
- **replaceAt(const Type &newElement, int index)**: Replaces the element at the specified index with a new element.
- **isExist(const Type &element)**: Checks if a given element exists in the list.
- **isItemAtEqual(const Type &element, int index)**: Checks if the element at the specified index is equal to a given element.

You will find in **singleLinkedList.h** implementation for single linked list

#### What about single linked list iterator?

### linkedListIterator Class

The `linkedListIterator` class represents an iterator for iterating through elements in a linked list.

#### Private Members

- **current**: A pointer to the current node being iterated over.

#### Public Member Functions

- **Default Constructor**: Constructs an iterator with a null current pointer.
- **Parameterized Constructor**: Constructs an iterator with the given node pointer.
- **operator\*()**: Overloads the dereference operator to return the data of the current node.
- **operator++()**: Overloads the increment operator to move the iterator to the next node in the list.
- **operator==()**: Overloads the equality operator to compare iterators for equality.
- **operator!=()**: Overloads the inequality operator to compare iterators for inequality.

You will find in **linkedListIterators.h** implementation for iterators

## Anime Girls Double Linked List Example

### Structure

In our whimsical world of anime girls, each node in the double linked list embodies the essence of a spirited character and boasts a structure characterized by three enchanting elements:

1. **Girl's Name**: The delightful moniker of our anime girl, adding a dash of personality to each node.
2. **Previous Pointer**: A magical link to the previous anime girl in the sequence, allowing for graceful reflections and backward traversal.
3. **Next Pointer**: An ethereal connection to the next anime girl in the sequence, paving the way for seamless forward traversal.

Sakura ↔ Asuna ↔ Rem ↔ Hinata ↔ Mikasa ↔ Zero Two ↔
Each anime girl in our double linked list is connected both forwards and backwards

//

### dNode Structure

The `dNode` structure represents a node in a doubly linked list. It stores an element of type `T` and pointers to the previous and next nodes in the list.

#### Members

- **data**: An element of type `T` stored in the node.
- **prev**: A pointer to the previous node in the list. Defaults to `nullptr`.
- **next**: A pointer to the next node in the list. Defaults to `nullptr`.

#### Constructors

- **Default Constructor**: Constructs a node with default-initialized data, and sets `prev` and `next` pointers to `nullptr`.
- **Parameterized Constructor**: Constructs a node with the given data, and sets `prev` and `next` pointers to `nullptr`.

You will find in **nodeType.h** the dnode type which we will use for the double linked list



### doubleLinkedList Class

The `doubleLinkedList` class represents a doubly linked list data structure. It stores elements of type `Type` in its nodes.

#### Private Members

- **count**: An integer variable to store the number of elements in the list.
- **first**: A pointer to the first node of the list.
- **last**: A pointer to the last node of the list.

#### Public Member Functions

- **Default Constructor**: Constructs an empty doubly linked list.
- **Copy Constructor**: Constructs a new doubly linked list as a copy of another doubly linked list.
- **Destructor**: Destroys the doubly linked list, deallocating memory.
- **copyList(const doubleLinkedList<Type>& otherList)**: Makes a copy of another doubly linked list.
- **operator=**: Overloads the assignment operator to assign one doubly linked list to another.
- **isEmpty()**: Checks if the list is empty.
- **print()**: Outputs the data contained in each node of the list.
- **size()**: Returns the number of nodes in the list.
- **destroyList()**: Deletes all nodes from the list.
- **front()**: Returns the data of the first element in the list.
- **back()**: Returns the data of the last element in the list.
- **begin()**: Returns an iterator pointing to the beginning of the list.
- **end()**: Returns an iterator pointing one element past the end of the list.
- **insertAtHead(const Type &element)**: Inserts an element at the beginning of the list.
- **insertAtTail(const Type &element)**: Inserts an element at the end of the list.
- **insertAt(const Type &element, int index)**: Inserts an element at the specified index.
- **removeAtHead()**: Removes the first element from the list.
- **removeAtTail()**: Removes the last element from the list.
- **removeAt(int index)**: Removes the element at the specified index.
- **swap(int firstItemIdx, int secondItemIdx)**: Swaps the positions of two elements in the list.
- **retrieveAt(int index)**: Retrieves the element at the specified index.
- **replaceAt(const Type &newElement, int index)**: Replaces the element at the specified index with a new element.
- **isExist(const Type &element)**: Checks if a given element exists in the list.
- **isItemAtEqual(const Type &element, int index)**: Checks if the element at the specified index is equal to a given element.

You will find in **doublyLinkedList.h** implementation for double linked list

### dLinkedListIterator Class

The `dLinkedListIterator` class represents an iterator for iterating through elements in a doubly linked list.

#### Private Members

- **current**: A pointer to the current node being iterated over.

#### Public Member Functions

- **Default Constructor**: Constructs an iterator with a null current pointer.
- **Parameterized Constructor**: Constructs an iterator with the given node pointer.
- **operator\*()**: Overloads the dereference operator to return the data of the current node.
- **operator++()**: Overloads the increment operator to move the iterator to the next node in the list.
- **operator==()**: Overloads the equality operator to compare iterators for equality.
- **operator!=()**: Overloads the inequality operator to compare iterators for inequality.

You will find in **linkedListIterators.h** implementation for iterators

## Anime Girls Circular Linked List Example

### Structure

In our enchanting realm of anime girls, the circular linked list adds an extra layer of magic, forming an eternal loop where each node embodies the spirit of a spirited character. This enchanting sequence is characterized by two whimsical elements:

1. **Girl's Name**: The delightful moniker of our anime girl, adding a dash of personality to each node.
2. **Next Pointer**: A magical link to the next anime girl in the sequence, forming an unbroken circle of companionship and camaraderie.

Sakura -> Asuna -> Rem -> Hinata -> Mikasa -> Sakura
Each anime girl is connected to the next, but the last one is the one in the beginning also.

//

##### We can use the same nodeType for the single linked list or construct a new one

### circularLinkedList Class

The `circularLinkedList` class represents a circular linked list data structure. It stores elements of type `Type` in its nodes.

#### Private Members

- **count**: An integer variable to store the number of elements in the list.
- **head**: A pointer to the head node of the list.

#### Public Member Functions

- **Default Constructor**: Constructs an empty circular linked list.
- **Copy Constructor**: Constructs a new circular linked list as a copy of another circular linked list.
- **Destructor**: Destroys the circular linked list, deallocating memory.
- **copyList(const circularLinkedList<Type>& otherList)**: Makes a copy of another circular linked list.
- **operator=**: Overloads the assignment operator to assign one circular linked list to another.
- **isEmpty()**: Checks if the list is empty.
- **print()**: Outputs the data contained in each node of the list.
- **size()**: Returns the number of nodes in the list.
- **destroyList()**: Deletes all nodes from the list.
- **front()**: Returns the data of the first element in the list.
- **back()**: Returns the data of the first element in the list. (as it's circular)
- **begin()**: Returns an iterator pointing to the beginning of the list.
- **end()**: Returns an iterator pointing to the beginning of the list (as it's circular, it's the same as `begin()`).
- **insertAtHead(const Type &element)**: Inserts an element at the beginning of the list.
- **insertAtTail(const Type &element)**: Inserts an element at the beginning of the list.
- **removeAtHead()**: Removes the first element from the list.
- **removeAtTail()**: Removes the first element from the list.
- **removeAt(int index)**: Removes the element at the specified index.
- **swap(int firstItemIdx, int secondItemIdx)**: Swaps the positions of two elements in the list.
- **retrieveAt(int index)**: Retrieves the element at the specified index.
- **replaceAt(const Type &newElement, int index)**: Replaces the element at the specified index with a new element.
- **isExist(const Type &element)**: Checks if a given element exists in the list.
- **isItemAtEqual(const Type &element, int index)**: Checks if the element at the specified index is equal to a given element.


