## Problem：
Determine whether an integer is a palindrome. Do this **without extra space**.


## Solution
需要注意的地方：
1. 负数有没有回文数字？ 这里给出的答案是没有。
2. 可不可以将数字转换为字符串？ No.注意题目要求是不使用额外存储空间。
3. 如果按照翻转数字的方法，有些数字翻转后会溢出，如何处理这种情况。

Solution:
与翻转数字的问题解法一致。由于回文数字翻转后与原数字相同，如果出现溢出的情况，那么一定不是回文数字。
