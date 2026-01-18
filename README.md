# Discrete Mathematics

Faculty of Electrical Engineering and Computing

---

## Lab 1

### Problem

For given nonnegative integers a, b, c, d and e, and a natural number L, your task is to determine how many
words of length L exist, under the restriction that they consist only of the letters A, B, C, D, and E, and that
each of these letters appears at most a, b, c, d, and e times, respectively.
Note: The program is expected to handle inputs satisfying a, b, c, d, e ≤ 10 and L ≤ 25. Instructors may
still ask you to input and test examples outside of these limits.

### Example Input

You enter the parameters a, b, c, d, e and L via the command line. An example of command-line input looks like
this:

```
2 2 2 2 2
10
```

### Example Output

The executable program should print the required result. An example of program output for the above input:

```
113400
```

Problem solution: [lab01.c](lab01.c)

---

## Lab 2

### Problem

For the given graph G, your task is to determine how many subgraphs of the graph G are isomorphic to the
cycle C3.

Note: It is expected that the program will perform the task for all graphs with no more than 12 vertices.

### Example Input

The executable file of the program should print a prompt for entering the name of the file containing information
about the graph, and that file should be located in the same folder as the program file. An example of the
program input (characters marked in red should be entered by the user):

```
graf.txt
```

The file graf.txt contains in the first line the number n (the number of vertices of the graph G), and in
the following n lines the adjacency matrix of the given graph (zeros and ones without spaces). An example of
the content of a text file with input looks like this:

```
5
01100
10100
11011
00101
00110
```

### Example Output

The program in the executable file should print the required solution with an appropriate message. An example
of the program output (characters marked in green are printed by the program, in this case for the given input
example):

```
Solution: 2
```

Problem solution: [lab02.c](lab02.c)

---

## Lab 3

### Problem

For a graph G, given by the number of vertices and its adjacency matrix, determine the maximum degree ∆ of
the vertices of the graph, and examine whether the graph G is ∆-edge-colorable.

### Example Input

In the executable file of the program, a prompt for entering the name of the file containing information about
the graph should be displayed, and this file should be located in the same folder as the program file. An example
of the program input (the characters marked in red should be entered manually by the user):

```
graf.txt
```

The file graf.txt contains in the first line the number n (the number of vertices of the graph G), and in
the next n lines the adjacency matrix of the given graph (zeros and ones without spaces). An example of the
contents of the text file with the input looks like this:

```
5
01100
10100
11011
00101
00110
```

### Example Output

The program in the executable file should print the corresponding ∆ in one line, and in the next line print 1 if
the graph is ∆-edge-colorable, or 0 if it is not.
An example of the program output (the characters marked in green are printed by the program, in this case for
the given example input):

```
4
1
```

Problem solution: [lab03.c](lab03.c)
