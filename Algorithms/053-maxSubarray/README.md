## Problem
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.


## Solution

1. 动态规划问题：
以nums[i]为结束的子序列的和为dp[i] = nums[i] + (dp[i-1]>0)?dp[i-1]:0;


2. 分治算法

