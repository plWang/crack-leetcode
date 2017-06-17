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

vector<vector<string> > generateMatrix(vector<vector<int> >& solution, int n) {
    vector<vector<string> > result;
    for (int i=0; i<solution.size(); i++) {
        vector<string> rowVal;
        for (int j=0; j<n; j++) {
            string s(n, '.');
            int col = solution[i][j];
            s[col] = 'Q'; 
            rowVal.push_back(s);
        }
        result.push_back(rowVal);
    }

    return result;
}

void backtrack(int n, vector<vector<int> >& solution, vector<int>& tempsol, int row, vector<int>& used) {
    if (row >= n) {
        solution.push_back(tempsol);
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

vector<vector<string> > solveNQueens(int n) {
    vector<vector<int> > solution;
    vector<int> tempsol;
    vector<int> used(n, 0);
    backtrack(n, solution, tempsol, 0, used);
    vector<vector<string> > result = generateMatrix(solution, n);
    return result;

}

void printMatrix(vector<vector<string> >& result) {
    int n = result[0].size();
    for (int i=0; i<result.size(); i++) {
        cout << "Solution: " << i << endl;
        for (int j=0; j<n; j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<string> > result = solveNQueens(n);
    printMatrix(result);
    return 0;
}