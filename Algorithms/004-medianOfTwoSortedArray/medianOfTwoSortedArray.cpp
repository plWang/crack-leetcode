#include <iostream>

using namespace std;

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