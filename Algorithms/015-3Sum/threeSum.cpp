#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    int length = nums.size();
    vector<vector<int>> res;
    vector<int> num;
    int index = 0;
    if (nums.empty()) return res;

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
            {
                if (flag !=0 && nums[last_lo] == nums[lo] && nums[last_hi] == nums[hi])
                {
                    lo++;
                    continue;
                }
                num.clear();
                num.push_back(nums[i]);
                num.push_back(nums[lo]);
                num.push_back(nums[hi]);
                res.push_back(num);
                last_lo = lo;
                last_hi = hi;
                lo++;
                flag = 1;
            }
            else if(nums[lo] + nums[hi] < t)
                lo++;
            else
                hi--;
        }
    }
    return res;
}


int main()
{
    vector<vector<int>> a;
    //vector<int> b{-1, 0, 1, 2, -1, -4};
    vector<int> b{0, 0, 0};
    a = threeSum(b, 0);
    for (int i=0; i< a.size(); i++)
    {
        cout << "[" << a[i][0] << "," << a[i][1] << "," << a[i][2] << "]" << "\n";
    }
    return 0;
}