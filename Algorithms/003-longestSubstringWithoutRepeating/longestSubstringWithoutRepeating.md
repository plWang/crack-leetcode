## Problem
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


## 思路
HashMap的方法。
建立一个长度为256（对应ASCII码？）的哈希字典。哈希字典中对应字符存储该字符出现的位置，通过判断dict[s[i]]是否大于之前存储的值来判断是否重复。
当出现重复字符时，计算当前字串的长度为dict[s[i]] - start