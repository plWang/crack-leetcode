#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int lo=0, hi=nums.size()-1;
    int mid;
    // find smallest value
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] > nums[hi]) lo = mid+1;
        else hi = mid;
    }
    // find target value
    int rot = lo;
    lo = 0, hi = nums.size()-1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int realmid = (mid + rot)%nums.size();
        if (nums[realmid] < target)
            lo = mid+1;
        else if (nums[realmid] > target)
            hi = mid-1;
        else return realmid;
    }

    return -1;
}

int main() {
    int array[] = {1, 3};
    int cnt = sizeof(array)/sizeof(int);
    vector<int> nums(array, array+cnt);
    int idx = search(nums, 3);
    cout << idx << endl;
    return 0;
}