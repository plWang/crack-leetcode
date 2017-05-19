#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

bool valid(string s) {
    if (s[0] == '0') return false;
    if (atoi(s.c_str())>= 1 && atoi(s.c_str()) <= 26) return true;
    else return false;
}

int numDecodings(string s) {
    int n = s.size();
    if (n == 0) return 0;
    if (s[0] == '0') return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i=1; i<n; i++) {
        if (valid(s.substr(i-1, 2)) && valid(s.substr(i,1)))
            dp[i+1] = dp[i] + dp[i-1];
        else if (valid(s.substr(i,1)))
            dp[i+1] = dp[i];
        else if (valid(s.substr(i-1, 2)))
            dp[i+1] = dp[i-1];
        else return 0;
    }

    return dp[n];
}

int main() {
    string s;
    cin >> s;
    //测试用例：
    // 0
    // 01
    // 001
    // 101
    // 110
    // 100
    // 123
    // 132
    // 130
    
    int res = numDecodings(s);
    cout << res << endl;
}

