#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidSudoku(vector<vector<char> >& board) {
    int index;
    // Rule 1: Each row must have the numbers 1-9 occuring just once
    for (int i = 0; i < 9; i++) {
        int hash_tab[9] = {0};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.' || (board[i][j] >= '1' && board[i][j] <= '9')) {
                if (board[i][j] == '.') continue;
                index = board[i][j] - '1';
                if (hash_tab[index] == 0) {
                    hash_tab[index] = 1;
                }
                else return false;
            }
            else return false;
        }
    }

    //Rule 2: Each column must have the numbers 1-9 occuring just once
    for (int j = 0; j < 9; j++) {
        int hash_tab[9] = {0};
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.' || (board[i][j] >= '1' && board[i][j] <= '9')) {
                if (board[i][j] == '.') continue;
                index = board[i][j] - '1';
                if (hash_tab[index] == 0) {
                    hash_tab[index] = 1;
                }
                else return false;
            }
            else return false;
        }
    }

    // Rule 3: the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hash_tab[9] = {0};
            int row = 3 * i;
            int col = 3 * j;
            for (int m = row; m < row+3; m++) {
                for (int n = col; n < col+3; n++) {
                    if (board[m][n] == '.' || (board[m][n] >= '1' && board[m][n] <= '9')) {
                        if (board[m][n] == '.') continue;
                        index = board[m][n] - '1';
                        if (hash_tab[index] == 0) {
                            hash_tab[index] = 1;
                        }
                        else return false;
                    }
                    else return false;
                }
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char> > board;
    vector<char> row;
    // ["..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."]
    vector<string> strs;
    strs.push_back("..5.....6");
    strs.push_back("....14...");
    strs.push_back(".........");
    strs.push_back(".....92..");
    strs.push_back("5....2...");
    strs.push_back(".......3.");
    strs.push_back("...54....");
    strs.push_back("3.....42.");
    strs.push_back("...27.6..");


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            row.push_back(strs[i][j]);
        }
        board.push_back(row);
        row.clear();
    }

    if (isValidSudoku(board)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}