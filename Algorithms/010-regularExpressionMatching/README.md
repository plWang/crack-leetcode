## Problem 
Implement regular expression matching with support for '.' and '*'.

```
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```

## Solution 

### Solution 1: 递归解法
'.'的处理情况很简单，关键在于'*'的情况
```
if *(p+1) == '*'， *p表示成x

1) 'x*'出现0次，那么只需要匹配*s和*(p+2)即可
递归调用isMatch(*s, *(p+2))

2) 'x*'出现1次，递归调用
isMatch(*(s+1), *(p+2))  (需首先满足*s == *p || *p == '.')

3) 'x*'出现大于1次，递归调用
isMatch(*(s+1), *p)   (需首先满足*s == *p || *p == '.')

if *(p+1) != '*'

首先需满足(*s == *p || *p == '.')， 然后匹配isMatch(*(s+1), *(p+2))

```

但是当pattern中出现大量的'x*'子串时，会被分解成很多重复的子问题，造成超时。

### Solution 2: 动态规划
前面递归的方法由于重复求解了很多相同的子问题造成超时，我们可以考虑使用动态规划的思想，将前面子串的匹配结果储存起来。
设置一个二维的bool数组dp[m+1][n+1], 其中dp[i][j]表示s[0,...,j-1]与p[0,...,j-1]是否匹配。

考虑两种情况
1）if p[j-1] != '*'
f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')

2) if p[j-1] == '*'，将p[j-2]表示成x

- 'x*'重复0次：f[i][j] = f[i][j-2]
- 'x*'重复大于等于1次：f[i][j] = f[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')
