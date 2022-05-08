Question 3

===========

Problem Statement: Identify the algorithm

============

Using what you know about specific data structures and their related algorithms, identify the algorithm in the code. In your own words, describe what this algorithm does and how it's different to other variations. If you're not able to identify the algorithm, describe the algorithm you're most familiar with from this class.

## Important

The code did not compile, and I saw that compilation is not a requirement, so I did not make any effort to make it compile. Just to let you know.

## Identify

Breadth first search of a binary tree with the given target.

## Description

This is an iterative implementation of breadth first search of a binary tree with the help of a queue data structure. The queue data structure is a FIFO data structure. First, the root of the tree has been added to the queue, then the root has been popped from the front of the queue, then its left and right child will be added to the queue if they exists. The traversal will be level by level, until the target has been found within the tree, and then the algorithm return whether the target has been found within the tree.

## Comparison with similar algorithms

There are other similar algorithms, for example, DFS traversal of a binary tree. The difference is that BFS searches level by level but DFS search exhaustively in one path as deep as possible and then backtrack if the element has not been found or return if the element has been found. In terms of efficiency, DFS usually performs faster in searching compared to BFS. There are also other traversing techniques, such as in-order, post-order, and pre-order, and they are different in just the matter of the order of traversal.

Rubric:
Identified: 8
Description: 12
Comparison with similar algorithms: 5
Total: 25
