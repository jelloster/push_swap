# 🔀 PushSwap 🔁

## Table of contents
- [Description](#-description-)
- [How the algorithm works](#-how-the-algorithm-works-)
- [Installation and compilation](#-installation-and-compilation-)
- [Running the program](#-running-the-program-)
- [Operations](#-operations-)

## ☆ Description ☆

**PushSwap** is an efficient sorting algorithm implemented in C that sorts a stack of integers using a series of predefined [operations](#-operations-). This program outputs the sequence of operations necessary to sort the integers. 

The algorithm utilizes two stacks, **stack A** and **stack B**. Users input unsorted integers into stack A, and after sorting, the goal is to return all integers to stack A in sorted order.

## ☆ How the algorithm works ☆

The algorithm starts out by transfering (almost) all integers from stack A to stack B in a reversed sorted order. The algorithm calculates and executes the cheapest route (meaning the least operations) for each integer to go to the right place. The "cheapest move" is determined by using straightforward calculations ([rotation_counters.c](https://github.com/jelloster/push_swap/blob/main/srcs/rotation_counters.c)). The last 3 remaining integers in stack A are sorted within the stack itself, as it can be done with few moves. And finally, integers are returned from stack B to stack A in the correct order, as the order gets reversed in the transfer from one stack to another.

## ☆ Installation and compilation ☆

1. Clone the repository
``` git clone https://github.com/jelloster/push_swap.git ```
2. Navigate to the repository and compile the program
``` make ```

## ☆ Running the program ☆

To execute the program, provide a series of integers as parameters. Note that duplicates are not permitted.

Example:

``` ./push_swap 5 3 2 4 1 9 7 ```

## ☆ Operations ☆

### Push x (pa/pb) ⏩

Push the topmost integer of stack x on top of the other stack.

Example of push A (pa):

```
1        1
2 6    2 6
3 5 ➔ 3 5
4 7    4 7
_ _    _ _
A B    A B
```

### Swap x (sa/sb) 🔁

Swap the places of the 2 topmost integers of stack x.

Example of swap A (sa):

```
1      2 
2 6    1 6
3 5 ➔ 3 5
4 7    4 7
_ _    _ _
A B    A B
```

### Rotate x ⤴️ (ra/rb)

Rotate stack x 1 step upwards. The first element becomes the last one.

Example of rotate A (ra):

```
1      2 
2 6    3 6
3 5 ➔ 4 5
4 7    1 7
_ _    _ _
A B    A B
```

### Reverse rotate x (rra/rrb) ⤵️

Rotate stack x 1 step downwards. The last element becomes the first one.

Example of reverse rotate A (ra):

```
1      4 
2 6    1 6
3 5 ➔ 2 5
4 7    3 7
_ _    _ _
A B    A B
```

### Double rotate (rr) ⤴️⤴️

Rotate both stacks at the same time.

Example of double rotate (rr):

```
1      2 
2 6    3 5
3 5 ➔ 4 7
4 7    1 6
_ _    _ _
A B    A B
```

### Double reverse rotate (rrr) ⤵️⤵️
Example of double reverse rotate (rrr):
```
1      4 
2 6    1 7
3 5 ➔ 2 6
4 7    3 5
_ _    _ _
A B    A B
```
