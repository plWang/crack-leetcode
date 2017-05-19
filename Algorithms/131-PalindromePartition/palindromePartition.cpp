#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
    if (s.size() == 1) return true;
    else {
        int i=0, j=s.size()-1;
        while (i <= j && s[i] == s[j]) {
            i++;
            j--;
        }
        if (i>j) return true;
        else return false;
    }
}

void backtrack(string s, vector<vector<string> >& solutions, vector<string>& tempsol, int begin) {
    if (begin == s.size()) {
        solutions.push_back(tempsol);
        return;
    }

    for (int i=begin; i<s.size(); i++) {
        if (isPalindrome(s.substr(begin, i-begin+1))) {
            tempsol.push_back(s.substr(begin, i-begin+1));
            backtrack(s, solutions, tempsol, i+1);
            tempsol.pop_back();
        }
    }
}


vector<vector<string> > partition(string s) {
    vector<vector<string> > solutions;
    vector<string> tempsol;
    backtrack(s, solutions, tempsol, 0);
    return solutions;
}

int main() {
    string s = "aabb";
    vector<vector<string> > result = partition(s);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}