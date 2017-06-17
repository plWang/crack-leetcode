#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int> candidates, vector<vector<int> >& solutions, vector<int>& tempsol, vector<int> taken) {
    if (tempsol.size() == candidates.size()) {
        solutions.push_back(tempsol);
        return;
    }

    for (int i=0; i<candidates.size(); i++) {
        if (taken[i] == 1 ||  (i>0 && candidates[i] == candidates[i-1] && taken[i-1] == 0)) 
            continue;
        else {
            tempsol.push_back(candidates[i]);
            taken[i] = 1;
            backtrack(candidates, solutions, tempsol, taken);
            tempsol.pop_back();
            taken[i] = 0;
        }
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > solutions;
    vector<int> tempsol;
    vector<int> taken(nums.size(), 0);
    sort(nums.begin(), nums.end());
    backtrack(nums, solutions, tempsol, taken);
    return solutions;
}

int main() {
    int array[] = {1, 1, 2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    vector<vector<int> > result = permuteUnique(nums);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}