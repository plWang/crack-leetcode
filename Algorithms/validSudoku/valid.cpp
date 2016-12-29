#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool isValidSudoku(vector<vector<char> > &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
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