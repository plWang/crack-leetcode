## Porblem

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

## 解题思路
二叉树的层次遍历与广度优先搜索的形式相同，都是使用一个队列来存储节点。此题的区别在于需要区分层次。
有两种解法，第一种是除了压入节点外，还同时压入节点所在的层数。这样就可以使用一个queue来实现。
另外一种较为方便的做法是使用两个队列，分别存储当前层和下一层的节点。

> 对照Binary Tree Zigzag Level Order Traversal
