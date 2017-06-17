#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size()-1;
    bool found = false;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            found = true;
            break;
        }
        if (nums[mid] < target) lo = mid+1;
        else hi = mid -1;
    }
    if (found) {
        int left = mid, right = mid;
        while (left >= 0 && nums[left] == target) left--;
        while (right < nums.size() && nums[right] == target) right++;
        vector<int> result;
        result.push_back(left+1);
        result.push_back(right-1);
        return result;
    }
    else return vector<int>(2, -1);
}