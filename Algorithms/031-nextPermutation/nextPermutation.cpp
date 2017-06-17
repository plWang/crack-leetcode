#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1) return;
    int i = nums.size()-1;
    while (i >= 0) {
        if (nums[i] > nums[i-1]) break;
        i--;
    }
    if (i == 0) {
        sort(nums.begin(), nums.end());
        return;
    }
    int j = nums.size()-1;
    while (j >= i) {
        if (nums[j] > nums[i-1]) break;
        j--;
    }

    swap(nums[i-1], nums[j]);
    sort(nums.begin()+i, nums.end());
}