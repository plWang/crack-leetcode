#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool backtrack(vector<vector<char> >& board, string tempsol, string word, vector<vector<int> > used, int i, int j, int k) {
    if (tempsol == word) return true;
    if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
    if (used[i][j]) return false;
    if (board[i][j] != word[k]) return false;

    bool result;
    tempsol.push_back(board[i][j]);
    k++;
    used[i][j] = 1;
    result = backtrack(board, tempsol, word, used, i-1, j);
    if (!result)
        result = backtrack(board, tempsol, word, used, i+1, j);
    if (!result)
        result = backtrack(board, tempsol, word, used, i, j-1);
    if (!result)
        result = backtrack(board, tempsol, word, used, i, j+1);

    used[i][j] = 0;
    k--;

    return result;
}

bool exist(vector<vector<char> >& board, string word) {
    int row = board.size();
    if (row == 0) return false;
    int col = board[0].size();
    if (col == 0) return false;
    if (row*col < word.size()) return false;

    string tempsol = "";
    vector<vector<int> > used(row, vector<int>(col, 0));

    for (int i=0; i<row; i++) 
        for (int j=0; j<col; j++) {
            bool result = backtrack(board, tempsol, word, used, i, j, 0);
            if (result) return true;
        }

    return false;
}

int main() {
    vector<vector<char> > board;

    vector<char> tmp;

    return 0;
}