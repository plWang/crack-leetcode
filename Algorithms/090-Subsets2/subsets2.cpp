#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void backtrack(vector<int> candidates, vector<int>& tempsol, vector<vector<int> >& solution, int begin) {
    solution.push_back(tempsol);
    for (int i=begin; i<candidates.size(); i++) {
        if (i == begin || candidates[i] != candidates[i-1]) {
            tempsol.push_back(candidates[i]);
            backtrack(candidates, tempsol, solution, i+1);
            tempsol.pop_back();
        }
    }
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > solution;
    vector<int> tempsol;
    sort(nums.begin(), nums.end());
    backtrack(nums, tempsol, solution, 0);
    return solution;
}

int main() {
    int nums[] = {4, 4, 4, 1, 4};
    vector<int> candidates(nums, nums+sizeof(nums)/sizeof(int));
    int target = 7;
    vector<vector<int> > result = subsets(candidates);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}