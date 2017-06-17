## Problem 
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

## Solution 

一个旋转图片问题的通用解法：

1. 顺时针旋转
1) first， reverse up and down（上下颠倒）
1 2 3        7 8 9     7 4 1
4 5 6   =>   4 5 6  => 8 5 2
7 8 9        1 2 3     9 6 3
2) second, swap the symmetry（对称翻转）

2. 逆时针旋转
1) 左右翻转
2）对称翻转
1 2 3      3 2 1      3 6 9
4 5 6  =>  6 5 4  =>  2 5 8
7 8 9      9 8 7      1 4 7


