## Problem

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

## Solution 

### 1. 一个错误思路：
求出二叉树的最大高度和最小高度，相差超过１的不平衡，否则平衡。
遇到的问题：当一棵树为类似[1,null,2,null,3]这样的树时
```
 1
  \
   2
    \
     3
```
只有一个叶子节点，树的最小高度和最大高度都是３，但是确是不平衡的，因为根节点1的左右子树高度相差超过1。
后来又试图通过添加限定叶子节点的个数等条件来判断。

但是后来证明，这样的想法是完全错误的。因为平衡二叉树要求任意一个子树的左右子树都应该是平衡，而不应该按照整体的高度来进行判断。
对于下面这样的树
```
      1
     / \
    2   2
   /     \
  3       3
 /         
4           
```
虽然整体高度上相差不超过1,但是并不是平衡树。


### 2.　解法1
使用递归的方法递归的判断每棵子树是否是平衡树。对于当前节点，分别求出当前节点的左子树的高度和右子树的高度，如果高度差小于1，则向下递归。

### 3.　解法2
第二种解法基于DFS。上一种解法中显式的调用了depth()函数求当前节点的深度，实际上有些节点遍历了好几遍。
使用DFS的方法，对于当前节点，调用dfs_height()方法分别求出左右子节点的高度，如果返回值是一个负数，则不是平衡树。否则当前节点就可以根据左右子节点的高度来计算当前节点的高度。这样自下而上的，可以在每个节点只遍历一遍的情况下解决问题，时间复杂度为O(N)。