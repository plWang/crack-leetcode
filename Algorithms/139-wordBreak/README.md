## Problem
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

## Solution

1. Backtracking 
但是在wordDict很大时，backtrack递归次数太多，时间复杂度高。

2. Dynamic Programming
用一个数组dp[]记录，其中dp[i]表示以元素i结尾的字符串组合是否存在

