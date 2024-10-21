# PushSwap

Push Swap is a sorting algorithm implemented in C that tells you how to efficiently sort a stack of integers using a series of predefined [operations](#operations). The algorithm works with two stacks, stack A and B. The unsorted integers given by the user are first placed into stack A and expected to all be returned to stack A after the sorting is completed.

## The algorithm

Simply put, the algoritm works by moving the numbers from stack A to stack B in (reversed) sorted order with the least amount of operations possible, and then moving the sorted integers back to stack A. It finds the "cheapest move" with simple calculations.

## Installation & compilation

1. Clone the repository
``` git clone https://github.com/jelloster/push_swap.git ```
2. Navigate to the repository and compile the program
``` make ```

## Running the program
The program is run by giving it a series of integers as parameters. Duplicates are not allowed.

Example:

``` ./push_swap 5 3 2 4 1 9 7 ```

## Operations

The pushswap algorithm works on the basis of 2 stacks. Stack A and B. The given integers are sorted to stack A using the following predetermined operations:

### Push x

Push the topmost integer of stack x on top of the other stack.

Example of push A (pa):

```
1       1
2 6   2 6
3 5 ➔ 3 5
4 7   4 7
_ _   _ _
A B   A B
```

### Swap x

Swap the places of the 2 topmost integers of stack x.

Example of swap A (sa):

```
1     2 
2 6   1 6
3 5 ➔ 3 5
4 7   4 7
_ _   _ _
A B   A B
```

### Rotate x

Rotate stack x 1 step upwards. The first element becomes the last one.

Example of rotate A (ra):

```
1     2 
2 6   3 6
3 5 ➔ 4 5
4 7   1 7
_ _   _ _
A B   A B
```

### Reverse rotate x

Rotate stack x 1 step downwards. The last element becomes the first one.

Example of reverse rotate A (ra):

```
1     4 
2 6   1 6
3 5 ➔ 2 5
4 7   3 7
_ _   _ _
A B   A B
```

### Double rotate

Rotate both stacks at the same time.

Example of double rotate (rrr):

```
1     2 
2 6   3 5
3 5 ➔ 4 7
4 7   1 6
_ _   _ _
A B   A B
```

### Double reverse rotate

```
1     4 
2 6   1 7
3 5 ➔ 2 6
4 7   3 5
_ _   _ _
A B   A B
```
