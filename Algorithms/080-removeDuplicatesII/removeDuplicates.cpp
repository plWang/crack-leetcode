int removeDuplicates(vector<int>& nums) {
    int length = 0;
    int cur = INT_MIN, count = 1;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == cur) {
            count++;
            if (count > 2) {
                nums.erase(nums.begin()+i);
                i--;
            }
            else 
                length++;
        }
        else {
            cur = nums[i];
            count = 1;
            length++;
        }
    }

    return length;
}

// a simple and clean solution
int removeDuplicates(vector<int>& nums) {
    int i=0;
    for (int n : nums) {
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    }

    return i;
}