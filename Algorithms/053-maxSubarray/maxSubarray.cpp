int maxSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int max = dp[0];
    for (int i=0; i<n; i++) {
        dp[i] = A[i] + (dp[i]>0)?dp[i]:0;
        max = (max>dp[i])?max:dp[i];
    }

    return max;
}

