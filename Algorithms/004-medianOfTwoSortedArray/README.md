## Problem

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

## Tags

Array

## Solution 

### Solution 1: 类似于归并排序
时间复杂度O(m+n)，题目要求复杂度O(log(m+n))，不符合要求

### Solution 2: Binary Search
首先我们要知道中位数的意义是什么，中位数就是将数组分为相同大小的两半的数，按照中位数切分后的两个数组中元素个数相同。

两个数组A, B，假设两个数组的大小分别为m, n(n >= m)
那么我们在i处将A数组切分为两半，在j处将B数组切分为两半
```
A[0], A[1], ..., A[i-1] | A[i], ..., A[m-1]

B[0], ..., B[j-1] | B[j], ..., B[n-1]
```

将A[0], ..., A[i-1]和B[0], ..., B[j-1]放在一起，作为left_part
A[i], ..., A[m-1]和B[j], ..., B[n-1]放在一起，作为right_part
```
    left_part     |   right_part    
A[0], ..., A[i-1] | A[i], ..., A[m]
B[0], ..., B[j-1] | B[j], ..., B[n]
                  |
```

同时保证A[i-1] <= B[j]且B[j-1] <= A[i]，这样left_part的数都比rigth_part的数要小。

我们要寻找的中位数就是i,j将两个数组分为数目相同的两个部分的位置，即
i+j == (m+n+1)/2  (left_part中元素的数量等于所有元素数量的一半)

j = (m+n+1)/2 - i  (要满足m<=n，这样才能保证j>=0)


设imin = 0, imax=m， 我们在[imin, imax]区间内寻找i的值

使用二分查找i的值，j = (m+n+1)/2

i = (imin + imax)/2
1) 如果A[i-1] <= B[j] && B[j-1] <= A[i], 那么此时的i就是我们要找的切分点，搜索结束。

2) 如果A[i-1] > B[j]
说明i太大了，这时要减小i, 令imax = i-1;

3) 如果B[j-1] > A[i]
说明i太小了，这时要增大i, 令imin = i+1;

当寻找到目标i之后，中位数
median = max(A[i-1], B[j-1]) (总数m+n为奇数个时)
median = (max(A[i-1], B[j-1]) + min(A[i], B[j])) / 2 （总数m+n是偶数个时）

#### Edge Case分析
下面分析一些edge case的情况，即i==0 || i == m || j == 0 || j == n

1) if ((i == 0 || j == n) && B[j-1] <= A[i])
那么i就是我们要寻找的目标点

2) if ((j == 0 || i == m) && A[i] <= B[j])
那么i就是我们要寻找的目标点
