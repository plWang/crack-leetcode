// greedy
bool canJump(vector<int>& nums) {
    int reach = 0;
    int n = nums.size();
    for (int i=0; i<n && i<=reach; i++) {
        reach = max(reach, i+nums[i]);
    }

    return i==n;
}