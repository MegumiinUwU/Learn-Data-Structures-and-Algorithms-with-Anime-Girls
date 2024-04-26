## Anime Girls Singly Linked List Example

### Structure
Each node in the singly linked list represents an anime girl and contains two parts:

1. **Girl's Name**: The name of the anime girl.
2. **Next Pointer**: A reference to the next anime girl in the sequence.


Sakura -> Asuna -> Rem -> Hinata -> Mikasa
In this example, each girl points to the next girl in the sequence, forming a singly linked list of anime girls.


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
