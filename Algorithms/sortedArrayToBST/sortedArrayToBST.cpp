#include <iostream>
#include "common.h"

using namespace std;

TreeNode* sortedArrayToBSTHelp(vector<int> &nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end + 1) / 2;
    TreeNode* curr = new TreeNode(0);
    curr->val = nums[mid];
    curr->left = sortedArrayToBSTHelp(nums, start, mid-1);
    curr->right = sortedArrayToBSTHelp(nums, mid+1, end);

    return curr;
}

TreeNode* sortedArrayToBST(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) return NULL;
    TreeNode* root = sortedArrayToBSTHelp(nums, 0, len-1);
    return root;
}



int main() {
    int num[] = {1, 3, 7, 9, 15, 20};
    // use iterator constructor to construct vector
    vector<int> nums (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = sortedArrayToBST(nums);
    travel(root);
}