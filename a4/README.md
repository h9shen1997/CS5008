## A4: More Practice With Lists, Stacks and Queues
This homework is to build upon previous assignment and add more implementation of doubly linked list functions and a deque data structure.

### Files included:
1. deque.h
2. deque.c
3. doubly.h
4. doubly.c
5. main.c
6. Makefile

### How to run the program
```make```

### Output of the program
The implementation is tested in two separate part:
1. testing of doubly linked list
2. testing of deque

Output from doubly linked list test:
```
Testing doubly linkedlist implementation...
Populate with some values first...
The initial values in the linkedlist are:
1 2 5 7 2 3 

After adding 1 to the right...
1 2 5 7 2 3 1 

After adding 8 to the right...
1 2 5 7 2 3 1 8 

After adding 5 to the left...
5 1 2 5 7 2 3 1 8 

After adding 3 to the left...
3 5 1 2 5 7 2 3 1 8 

After removing from the left...
5 1 2 5 7 2 3 1 8 

After removing from the right...
5 1 2 5 7 2 3 1 

After removing from index 1...
5 2 5 7 2 3 1 

After removing from index 4...
5 2 5 7 3 1 

After inserting 4 at index 3...
5 2 5 4 7 3 1 

After inserting 2 at index 1...
5 2 2 5 4 7 3 1 

Done testing for doubly linkedlist!
```
Output from deque test:
```
Testing deque implementation...
Push 3 to the left...
3 

Push 4 to the left...
4 3 

Push 1 to the left...
1 4 3 

Push 2 to the right...
1 4 3 2 

Push 8 to the right...
1 4 3 2 8 

Peeking element on the left, which is 1.
Peeking element on the right, which is 8.
Pop from left...
4 3 2 8 

Pop from left...
3 2 8 

Pop from right...
3 2 

Done testing for deque!
```

### Challenges and lesson learned
The most difficult challenge I found during this assignment was to implement InsertAt and RemoveAt methods in doubly.c. I needed to make sure that pointer manipulation was correct and the values were inserted at the correct index and the element was removed at the correct index. I have learned how to implement doubly linked list and deque using doubly linked list. Knowing the foundation and logics behind the deque data structure was quite interesting. I also realized that doubly linked list can be very useful to implement other data structure and still ensure efficiency.