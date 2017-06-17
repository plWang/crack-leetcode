void sortColors(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    int i = 0;
    for (int i=0; i<nums.size(); i++) {
        while (nums[i] == 2 && i<right)
            swap(nums[i], nums[right--]);
        while (nums[i] == 0 && i>left)
            swap(nums[i], nums[left++]);
    }
}