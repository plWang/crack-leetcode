#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    int lo = 0, hi = nums.size()-1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid+1;
        else hi = mid-1;
    }

    if (target > nums[mid]) return mid+1;
    else return mid;
}