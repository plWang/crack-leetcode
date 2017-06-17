#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool ifAttack(vector<int>& tempsol, int col, int row) {
    for (int i=0; i<tempsol.size(); i++) {
        if (fabs(row-i) == fabs(col-tempsol[i])) return true;
    }
    return false;
}


void backtrack(int n, int& solution, vector<int>& tempsol, int row, vector<int>& used) {
    if (row >= n) {
        solution++;
        return;
    }

    for (int i=0; i<n; i++) {
        if (!used[i] && !ifAttack(tempsol, i, row)) {
            tempsol.push_back(i);
            used[i] = 1;
            backtrack(n, solution, tempsol, row+1, used);
            tempsol.pop_back();
            used[i] = 0;
        }
    }
}

int totalNQueens(int n) {
    int solution = 0;
    vector<int> tempsol;
    vector<int> used(n, 0);
    backtrack(n, solution, tempsol, 0, used);
    return solution;

}

int main() {
    int n;
    cin >> n;
    vector<vector<string> > result = solveNQueens(n);
    printMatrix(result);
    return 0;
}