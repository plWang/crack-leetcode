#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "math.h"

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int diff = 10000;
    int closetVal;

    sort(nums.begin(), nums.end());
    int last_lo = 0;
    int last_hi = 0;
    int flag = 0;
    for (int i=0; i<nums.size()-1; i++)
    {
        int t = target - nums[i];
        int lo = i + 1;
        int hi = nums.size()-1;
        while(lo < hi)
        {
            if (nums[lo] + nums[hi] == t)
                return target;
            else if(nums[lo] + nums[hi] < t) {
                if (fabs(nums[lo]+nums[hi]-t) < diff) {
                    diff = fabs(nums[lo]+nums[hi]-t);
                    closetVal = nums[lo]+nums[hi]+nums[i];
                }
                lo++;
            }
            else {
                if (fabs(nums[lo]+nums[hi]-t) < diff) {
                    diff = fabs(nums[lo]+nums[hi]-t);
                    closetVal = nums[lo]+nums[hi]+nums[i];
                }
                hi--;
            }
        }
    }
    return closetVal;
}


int main() {
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int target = 1;
    int a = threeSumClosest(nums, target);
    cout << a << endl;
    return 0;
}