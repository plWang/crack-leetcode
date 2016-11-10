#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> lh, pair<int, int> rh)
{
  return lh.first < rh.first;
}

vector<int> twoSum(vector<int>& nums, int target) {
    int length = nums.size();
    int lo = 0;
    int hi = nums.size()-1;
    vector<int> res;
    vector<pair<int, int> > num;
    int index = 0;
    for(vector<int>::iterator iter = nums.begin();
                            iter != nums.end(); ++iter, ++index) {
        num.push_back(make_pair(*iter, index));
    }
    sort(num.begin(), num.end(), compare);
    while(lo < hi)
    {
        if (num[lo].first + num[hi].first == target)
        {
            res.push_back(num[lo].second);
            res.push_back(num[hi].second);
            ++lo;
        }
        else if(num[lo].first + num[hi].first < target)
            lo++;
        else
            hi--;
    }
    return res;
}

int main()
{
    vector<int> a= {3, 2,5, 7};
    int target = 8;
    vector<int> result;
    result = twoSum(a, target);
    printf("[ %d, %d]", result[0], result[1]);
    return 0;
}