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