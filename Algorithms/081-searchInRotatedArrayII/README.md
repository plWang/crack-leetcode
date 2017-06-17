## Problem
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

## Solution 
### 1. Solution for "Search in Rotated Sorted Array"
- **Solution 1:** find the smallest value, then binary searc with ratated in account
1) 找到数组中的最小值
```c++
while (lo < hi) {
    mid = lo + (hi-lo)/2;
    if (nums[mid] > nums[hi])  //mid在raotated的部分，最小值一定在mid和hi之间
        lo = mid+1;        
    else 
        hi = mid-1;
}
```

2）考虑旋转值的二分查找
```c++
int rotate  = lo; //旋转了几个数字
int n = nums.size();
lo = 0, hi = n-1;
while (lo <= hi) {
    mid = lo + (hi - lo)/2;
    int realmid = (mid + rotate)% n;
    if (nums[realmid] == target)
        return realmid;
    else if (nums[realmid] < target)
        lo = mid+1;
    else 
        hi = mid-1; 
}

return -1;
```

- **Solution 2:** 
```c++
int lo = 0, hi = n-1;
while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < nums[lo]) {   // 说明mi和hi之间的数字是有序的
        if (tartget > nums[mid] && target <= nums[hi])  // target在mid和hi之间
            lo = mid+1;
        else 
            hi = mid-1;
    }
    else {                           // 说明lo和mid之间的数字是有序的
        if (target >= nums[lo] && target < nums[mid])
            hi = mid-1;
        else 
            lo = mid+1;
    }
}
```

### 2. Solutioin for "Search in Rotated Sorted Array II"
same idea with Problem "Search in Rotated Sorted Array" solution 2.
只是由于可能会出现重复元素，那么就会出现nums[mid] == nums[lo]的情况，
因此根据nums[lo] <= nums[mid]不能推断出lo和mid之间是有序的，如[3,1,3,3,3,3]，
我们必须单独处理这种情况。这种情况时可以确定的是nums[lo]==nums[mid]==nums[hi]，因此只需要判断这种情况，当出现时将lo和hi指针分别向中间移动一次即可。

```c++
int lo = 0, hi = n-1;
while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (nums[mid] == target) return true;
    if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
        lo++;
        hi--;
    }
    else if (nums[mid] < nums[lo]) { // mid到hi之间是有序的
        if (target > nums[mid] && target <= nums[hi])
            lo = mid+1;
        else 
            hi = mid-1;
    }
    else {                                 // lo和mid之间是有序的
        if (target >= nums[lo] && target < nums[mid])
            hi = mid-1;
        else 
            lo = mid+1;
    }
}

return false;
```