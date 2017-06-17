## Problem 
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


## Solution

可以用动态规划的方法求解。
给定一个序列1...n，要构造二叉搜索树，我们可以选定一个数i作为根节点，那么1...i-1都在左子树上，i+1...n都在右子树上。
设
G(n): 序列1-n对应的不同的二叉搜索树的个数
F(i, n), 1 <= i <= n: 序列1-n, 以i为根节点的二叉搜索树的个数

那么有
G(n) = F(1,n) + F(2, n) + ... + F(n, n)
我们可以知道
G(0) = 1, G(1) = 1;

选定一个数i作为根节点，以F(3, 7)为例，它是以3为根节点的树，左子树上是序列[1,2]构成的二叉搜索树，即G(2)。右子树上是序列[4,5,6,7]构成的二叉树，即G(4)。
所以有
F(i,n) = G(i-1) * G(n-i), 1 <= i <= n

根据上面的递推公式，我们可以迭代的求解出G(n)


