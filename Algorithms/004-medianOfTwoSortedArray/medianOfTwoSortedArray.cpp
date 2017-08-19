#include <iostream>

using namespace std;


// Solution 1: 归并方法， 复杂度O(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int count=0;
    int i=0, j=0;
    int target = (n+m)/2;
    int cur;
    int a = 0, b = 0;
    while (count <= target) {
        if (i >= n) {
            cur = nums2[j];
            j++;
        }
        else if (j >= m) {
            cur = nums1[i];
            i++;
        }
        else {
            if (nums1[i] < nums2[j]) {
                cur = nums1[i];
                i++;
            }
            else {
                cur = nums2[j];
                j++;
            }
        }
        count++;
        if (count == target) a = cur;
        if (count == target+1) b = cur;

    }

    if ((n+m)%2 == 0) return (a+b)/2.0;
    else return b;

}


// Solution 2: 二分查找， 复杂度O(log(min(m,n)))
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    if (m > n) return findMedianSortedArrays(B, A);  //make sure m <= n
    int max_left, min_right, i, j;

    int imin = 0, imax = m;
    int half = (m + n + 1)/2;
    while (imin <= imax) {
        i = (imin + imax)/2;
        j = half - i;
        if (i > 0 && A[i-1] > B[j]) {
            imax = i-1;
        }
        else if (i < m && B[j-1] > A[i]) {
            imin = i+1;
        }
        else {
            if (i == 0)
                max_left = B[j-1];
            else if (j == 0)
                max_left = A[i-1];
            else
                max_left = max(A[i-1], B[j-1]);

            if ((m+n)%2 == 1) return max_left;

            if (i == m)
                min_right = B[j];
            else if (j == n)
                min_right = A[i];
            else 
                min_right = min(A[i], B[j]);

            return (max_left + min_right)/2.0;
        }
    }

    return -1;
}