bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;

    int lo = 0, hi = n-1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
            lo++;
            hi--;
        }
        else if (nums[mid] < nums[lo]) { // mid到hi之间是有序的
            if (target > nums[mid] && target <= nums[hi])
                lo = mid+1;
            else 
                hi = mid-1;
        }
        else {                                 // lo和mid之间是有序的
            if (target >= nums[lo] && target < nums[mid])
                hi = mid-1;
            else 
                lo = mid+1;
        }
    }

    return false;

}