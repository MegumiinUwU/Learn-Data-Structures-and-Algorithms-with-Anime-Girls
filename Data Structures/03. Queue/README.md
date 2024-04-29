🌸 **Discovering Queues with Anime Girls** 🎀

Imagine a queue as a line of friends eagerly waiting to enter a magical theme park. Each girl holds a ticket in her hand, patiently waiting for her turn to experience the thrilling rides and attractions. It's like a line for your favorite anime convention, where everyone is filled with excitement and anticipation!

Now, let's dive into how our queue operates:

1. **Adding Girls to the Queue**: When a new girl wants to join our adventure, she excitedly joins the back of our queue, ready to experience the magic with us. Just like joining a line for a concert, she patiently waits for her turn to enter the enchanting world ahead.

2. **Removing Girls from the Queue**: As we enter the theme park, the girl at the front of our queue steps forward to enjoy the first ride. She experiences the thrill of the roller coaster while the rest of us cheer her on from behind.

3. **First-in, First-out (FIFO)**: Our queue operates on the principle of "first-in, first-out" – the first girl to join the queue is the first one to experience the magic. It's like taking turns at a cosplay contest, where everyone gets a chance to shine!

4. **Dynamic Line Formation**: Our queue can dynamically grow and shrink as more girls join us or leave to explore other adventures.

<img src="Queue 01.jpg" alt="Single Linked List" style="width: 300px; height: auto;">




### linkedQueueType Class

The `linkedQueueType` class represents a queue data structure implemented using a linked list. It stores elements of type `Type`.

#### Private Members

- **frontPtr**: A pointer to the front node of the queue.
- **rearPtr**: A pointer to the rear node of the queue.
- **count**: An integer variable to store the number of elements in the queue.

#### Public Member Functions

- **Default Constructor**: Constructs an empty queue.
- **Copy Constructor**: Constructs a new queue as a copy of another queue.
- **Destructor**: Destroys the queue, deallocating memory.
- **Assignment Operator= Overload**: Overloads the assignment operator to assign one queue to another.
- **enqueue(const Type& element)**: Enqueues an element into the queue.
- **dequeue()**: Dequeues an element from the queue and returns it.
- **first()**: Returns the front element of the queue without removing it.
- **isEmpty()**: Checks if the queue is empty.
- **queueSize()**: Returns the number of elements in the queue.
- **clear()**: Clears the queue, removing all elements.
- **print()**: Prints the elements of the queue.

You can find the implementation details in **linkedlistQueue.h** but remember to study linked lists first UwU

### arrayQueueType Class

The `arrayQueueType` class represents a queue data structure implemented using an array. It stores elements of type `Type`.

#### Private Members

- **queueArray**: An array to store the elements of the queue.
- **maxSize**: An integer representing the maximum size of the queue.
- **front**: An integer representing the index of the front element in the queue.
- **rear**: An integer representing the index of the rear element in the queue.
- **count**: An integer representing the number of elements in the queue.

#### Public Member Functions

- **Default Constructor**: Constructs an empty queue with the specified maximum size.
- **Copy Constructor**: Constructs a new queue as a copy of another queue.
- **Destructor**: Destroys the queue, deallocating memory.
- **Assignment Operator= Overload**: Overloads the assignment operator to assign one queue to another.
- **enqueue(const Type& element)**: Enqueues an element into the queue.
- **dequeue()**: Dequeues an element from the queue and returns it.
- **first()**: Returns the front element of the queue without removing it.
- **isEmpty()**: Checks if the queue is empty.
- **queueSize()**: Returns the number of elements in the queue.
- **clear()**: Clears the queue, removing all elements.
- **print()**: Prints the elements of the queue.

You can find the implementation details in **arrayQueue.h**


