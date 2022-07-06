# Mastering the Arts of Computer Science 

Let's study data structures and algorithms!

## ArrayList

| Operation     | Runtime       |
| ------------- |:-------------:|
| add           | O(n)  -> O(1) amortized        |
| add (on specified index)   | O(n)          |
| find (by value)          | O(n)     |
| remove (by index)       | O(n)     |
| get (by index)          | O(1)     |
| set  (on valid index)         | O(1)     |
| clear         | O(1)     |

### Insertion on last index runtime

The way we implemented the ArrayList here follows the traditional algorithm of doubling the array's size whenever we reach it's limit when inserting. This means the operation will be O(1) for the majority of the cases, however once in a while it will have to stop to create a new array with double the size and then copy the existing values from the old array into the new one.

If we inserted N items on the array, it will have doubled on N / 2, and then on N / 4, and N / 8...

If we follow through the sum of (N/2) + (N+4) + ... + 2 + 1 we will have a value that is just under N. This means that, to insert N items, we spent O(N) time, which leads us to the amortized runtime of O(1) for insertions on ArrayList.

### Insertion on a given index

When inserting on a specific index, we'll always have to iterate through the array in order to reorganize it, so this will always be O(n).

### Others

The rest should be pretty intuitive. For finding and removing we will always have to iterate the array, so it will roughly be O(N).

And set, get (by index) and clearig is O(1) because no iterating is required.

## Linked List

These data structures are widely used to implement popular solutions such as hash tables, stacks and queues. It's main advantage when compared to simple arrays is that the data is not stored in continuous positions in memory, which allows us to mutate the list without having to reorganize all the data around it.

The nature of the data structure makes the insertion and deletion of items very easy due to having no need to reorganize the whole thing, meaning these operations can be done in constant time (O(1)) ASSUMING we are already iterating the list.

In short, inserting during runtime is super fast, but if we have to iterate the list to get there that advantage kinda fades.

Also important to mention that the size of the list does not need to be known in advance here. We can increase it in runtime without any issues.

However, operations to retrieve data from specific positions or with specific values are very inefficient due to the lack of indexing, meaning that most of these might have to go through the entire list to find something (O(N)).

The list implemented on this project is a Singly Linked List of String values, with the following operations:

- append (insert at last position, innefficient since we need to iterate the list to insert at the end)
- appendAtStart (insert item at first position)
- insert (insert item at given position)
- remove (remove first occurence of a key)
- get (find item by index)
- find (find item by value)

| Operation     | Runtime       |
| ------------- |:-------------:|
| append        | O(n)     |
| appendAtStart | O(1)     |
| insert        | O(n)     |
| remove        | O(n)     |
| find          | O(n)     |
| get           | O(n)     |

Removing from the end or from the start (like a queue or stack) would be O(1).