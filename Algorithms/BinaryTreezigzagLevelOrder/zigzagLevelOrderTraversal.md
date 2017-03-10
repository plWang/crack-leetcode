# Binary Tree zigzag Level Order Traversal

## Problem

Given a binary tree, return the *zigzag level order* traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7

```

return its zigzag level order traversal as:

```
[
  [3],
  [20,9],
  [15,7]
]
```

## 解题思路

二叉树层序访问的变种，只是从左到右变为从左到右，从右到左交替。

用两个栈来存储当前层和下一层的节点可以实现这样的访问。因为栈是先进后出的，节点push进stack与pop出stack的顺序正好是相反的。假设当前层currLevel pop出的第一个节点是该层最左边的节点x，那么将x->left和x->right依次压入下一层的栈nextLevel中。这样当下一层pop时，x->right和x->left就是最后pop出的。

同时，还要注意的是将左右子节点push进stack中的顺序。从左向右访问时，应该先push左节点，再push右节点；从右向左访问时，则正好相反，应该先push右节点，再push左节点。这可以用一个标志变量来指示。