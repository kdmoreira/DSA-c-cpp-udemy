#include <stdio.h>
#include <stdlib.h>

/* Trees Terminology: Root (topmost node); Parent; Child; Siblings; Descendants; Ancestors;
Degree of a Node (how many direct children it has, not descendants); Degree of a Tree (pre-decided
not possible to determine by looking, but we can determine the minimum, e.g. "at least 3");
Internal/External Nodes (Non-leaf Nodes/Leaf Nodes or Non-Terminal Nodes/Terminal Nodes):
External/Terminal/Leaf Nodes: degree 0, Internal/Non-leaf/Non-Terminal Nodes: degree other than 0;
Levels: counts nodes, starts from 1 (root), level 2 (root's children) and so on;
Height: counts edges, starts from 0 (root) and so on; Forest: collection of trees (remember that
a single node can also be considered a tree)

Binary Tree: nodes must have 0, 1 or 2 children.

Number of binary trees using N nodes:
1- Unlabeled nodes: Catalan formula: T(n)=(2n Cn)/n+1 i.e. T(5)=(2*5 C5)/5+1 -> T(5)=(10 C5)/6 ->
T(5)=((10*9*8*7*6)/5!)/6 -> T(5) = 42 (combination formula)
Other formula: T(n)=SUMMATION(upper limit: n, lower limit i=1) of T(i-1)*T(n-i), a recursive formula
Max. height: 2^(n-1)
2- Labeled nodes: T(n)=((2n Cn)/n+1)*n! -> Catalan formula for shapes * factorial for permutation/filling

Height vs Nodes: find height by n of nodes and vice-versa
1- Height is given:
Min. number of nodes: n = h + 1
Max. number of nodes: sum of the terms of a GP series: n = a+ar+ar^2+ar^3+...+ar^k
which is n = (a(r^(k+1)-1))/(r-1) or simply n = 2^(h+1)-1
2- Nodes are given:
Min. height: h = (log base2 (n+1)) - 1
Max. height: h = n - 1
In conclusion:
Height of binary tree: (log base2 (n+1)) - 1 <= h <= n - 1 that is: logarithmic to linear: O(log n) to O(n)
Number of nodes in a binary tree: h + 1 <= n <= 2^(h+1)-1 that is: linear to exponential: O(n) to O(2^n)

Internal Nodes vs External Nodes:
There's a relationship between nodes with degree 2 and degree 0, but not degree 1:
deg(0) = deg(2) + 1, this is always true for binary trees

Strict Binary Tree:
Definition: nodes can have either 0 or 2 children, not 1 children.
Height vs Nodes:
If height is given:
For the max. number of nodes is the same for a general binary tree formula: n = 2^(h+1) - 1
For the min. number of nodes we need a formula: n = 2h + 1
If nodes are given:
Max: h = (log base2 (n+1)) - 1
Min: h = (n - 1)/2
This means height is ranging from logarithmic to linear, similar to simple binary tree.
Internal vs External nodes: external nodes are greater than internal nodes by one: e = i + 1

N-ary Trees:
N stands for Nodes, it's a reference to the degree of the tree (every node can have at most N children)
For example: nodes in a 3-ary tree can have from 0 up to 3 nodes, each node has a "capacity" of having
3 children, even if they have less.
Strict N-ary trees: every node can have either 0 children or exactly N children.
Height vs Node:
Height is given:
Min: n = mh + 1 (m being the degree of the tree).
Max: n = 1 + m + m^2 + m^3 + m^4...+m^h. This is: n = (m^(m+1)-1)/m-1
Nodes are given:
Min: h = (n-1)/m
Max: h = log base m [n(m-1)+1] - 1
Internal vs External Nodes: e = (m-1)i + 1

Representation of Binary Tree:
Store the elements and preserve the relationships between them.
Array: if an element it's at index i, its left child is at index 2*i, its
right child at index 2*i+1 and its parent at i/2 (floor value). By filling the elements level by
level, this formula will be automatically followed.
Linked List: Node with data and two pointers for left child and right child (doubly linked list).
Since it's a dynamic structure, it's created in heap. The leaf nodes have NULL pointers.
For n Nodes, there are n+1 NULL pointers (similar to Strict Binary Tree's e=i+1).

Full vs Complete Binary Trees:
Full: binary tree of height h with its maximum number of nodes: n = 2^(h+1)-1
In an array[8]: ABCDEFGH for a tree of height 2.
Complete: no blank spaces between the elements, for height 2, in an array[8], ABCDEF_ _ would suffice.
If it was: ABCD_ _E, that wouldn't be a complete binary tree.
For arrays, we shouldn't have spaces inside arrays (if an element is deleted, we should shift the rest),
this is why we need complete binary trees. If the tree forces us to leave blank spaces, then it's not
suitable for arrays. Full and Complete ones are suitable. Note: A complete is not always a full one, but
a full one is always a complete one.

Strict vs Complete Binary Trees: different terminology.
Strict: also called "proper" binary trees, some also can call them "complete". However, contrary to the
complete ones in the previous topic, they could have empty spaces between elements in an array, since the
sole requirement is that every node can have either degree 0 or 2.
Complete: (almost complete), when represented in an array there mustn't be any empty elements.

Traversals:
Visiting all the elements, in a linear or non-linear manner. The orders are known as:
Preorder: visit(node)/root, preorder(left subtree), preorder(right subtree)
Inorder: preorder(left subtree), visit(node)/root, preorder(right subtree)
Postorder: preorder(left subtree), preorder(right subtree), visit(node)/root
Level order: level by level (top to bottom).
Tip: break a bigger problem into smaller ones, that is, a big tree into smaller subtrees.
Easy Method 1: connecting nodes to a line below the tree.
Easy Method 2: drawing a mark near the node and tracing along the borders of the tree.
Easy Method 3: point your finger according to pre/in/post order and move it along the border,
starting from above the root. */

int main(void)
{
    return 0;
}
