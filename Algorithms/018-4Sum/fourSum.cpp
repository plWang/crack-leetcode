#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i=0; i<n-3; i++) {
        if (i>0 && nums[i] == nums[i-1]) continue; //第一层去重
        if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
        if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
        for (int j=i+1; j<n-2; j++) {
            if(j>i+1&&nums[j]==nums[j-1]) continue; //第二层去重
            if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
            if (nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
            int t = target-nums[i]-nums[j];
            int lo = j+1, hi = n-1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] == t) {
                    int arr[] = {nums[i], nums[j], nums[lo], nums[hi]};
                    vector<int> tmp(arr, arr+sizeof(arr)/sizeof(int));
                    result.push_back(tmp);
                    do {lo++;} while (lo<hi && nums[lo-1] == nums[lo]);  //第三层去重
                    do {hi--;} while (lo<hi && nums[hi] == nums[hi+1]);
                }
                else if (nums[lo] + nums[hi] < t) lo++;
                else hi--;
            }
        }
    }

    return result;
}

int main() {
    int arr[] = {-3,-2,-1,0,0,1,2,3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int target = 0;
    vector<vector<int> > result = fourSum(nums, target);
    for (int i=0; i< result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) 
            cout << result[i][j] << " ";
        cout << endl;
    }
}