#include <iostream>
#include <string>

using namespace std;


// Solution 1: Recursive
bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();

    if (p[1] == '*') {
        if (s[0] ==  p[0] || (s[0] != '\0' && p[0] == '.')) {
            return isMatch(s.substr(1), p.substr(2)) || isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
        }
        else {
            return isMatch(s, p.substr(2));
        }
    }
    else {
        if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
            return isMatch(s.substr(1), p.substr(1));
        else
            return false;
    }
}

// Solution 2: Dynamic Programming
// 设置一个二维的bool数组dp[m+1][n+1], 其中dp[i][j]表示s[0,...,j-1]与p[0,...,j-1]是否匹配。

// 考虑两种情况
// 1）if p[j-1] != '*'
// f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')

// 2) if p[j-1] == '*'，将p[j-2]表示成x

// - 'x*'重复0次：f[i][j] = f[i][j-2]
// - 'x*'重复大于等于1次：f[i][j] = f[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    // p[0, 1, ..., n-1]与空字符串匹配：当且仅当p[j-1] == '*' 且p[j-3]与空字符串匹配
    for (int j=1; j<=n; j++) {
        dp[0][j] = (j>1) && (p[j-1] == '*') && dp[0][j-2];
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (p[j-1] != '*') {
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
            else {
                dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            }
        }
    }

    return dp[m][n];
}


int main() {
    string str, pattern;
    cin >> str >> pattern;
    if (isMatch(str, pattern))
        cout << "Match" << endl;
    else 
        cout << "not match" << endl;
    return 0;
}