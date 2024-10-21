# PushSwap

Push Swap is a sorting algorithm implemented in C that efficiently sorts a stack of integers using a series of predefined operations.


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
