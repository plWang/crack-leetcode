bool inDict(string s, vector<string>& wordDict) {
    for (int i=0; i<wordDict.size(); i++) {
        if (s[0] != wordDict[i][0]) continue;
        else if (s == wordDict[i])
            return true;
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    sort(wordDict.begin(), wordDict.end());
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i=1; i<=n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (dp[j]) {
                if (inDict(s.substr(j,i-j), wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[n];
}