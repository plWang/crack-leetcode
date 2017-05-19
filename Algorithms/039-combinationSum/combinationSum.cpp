#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void combinationSumHelp(vector<int> candidates, int target, vector<vector<int> >& result, vector<int>& combination, int begin) {
    if (!target) {
        result.push_back(combination);
        return;
    }

    for (int i=begin; i<candidates.size() && candidates[i] <= target; i++) { // candidates从索引为begin的值开始，为了避免得到重复解
        combination.push_back(candidates[i]);
        combinationSumHelp(candidates, target-candidates[i], result, combination, i);
        combination.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > result;
    vector<int> combination;
    combinationSumHelp(candidates, target, result, combination, 0);
    return result;
}

int main() {
    int nums[] = {2, 3, 6, 7};
    vector<int> candidates(nums, nums+sizeof(nums)/sizeof(int));
    int target = 7;
    vector<vector<int> > result = combinationSum(candidates, target);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

