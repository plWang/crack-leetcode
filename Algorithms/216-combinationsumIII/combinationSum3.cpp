#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int> >& solutions, vector<int>& tempsol, int k, int n, int& sum, int& used, int i) {
    if (used > k) return;
    if (used == k) {
        if (sum == n) solutions.push_back(tempsol);
        return;
    }

    for (int j=i; j<=9; j++) {
        tempsol.push_back(j);
        used++;
        sum += j;
        backtrack(solutions, tempsol, k, n, sum, used, j+1);
        tempsol.pop_back();
        used--;
        sum -= j;
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > solutions;
    vector<int> tempsol;
    int used = 0;
    int sum = 0;
    backtrack(solutions, tempsol, k, n, sum, used, 1);
    return solutions;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int> > solutions = combinationSum3(k, n);
    for (int i=0; i<solutions.size(); i++) {
        for (int j=0; j<k; j++) {
            cout << solutions[i][j] << " ";
        }
        cout << endl;
    }
}