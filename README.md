Kth Smallest in BST


Given the root node of a binary search tree and a number k, find out the kth smallest element (1-indexed) in the BST.

Note: You can assume that k <= number of nodes.

Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
The third line contains an integer k.
Output Format
For each test case, the output contains an integer with the value of the kth smallest element in BST.

Sample Input
4
9
2 1 3 -1 -1 -1 5 4 7
4
7
6 3 21 -1 -1 -1 89
1
12
8 3 9 -1 4 -1 10 -1 -1 -1 12 11
7
4
28 14 -1 11
2
Expected Output
4
3
12
14