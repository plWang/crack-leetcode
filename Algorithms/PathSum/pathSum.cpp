#include <iostream>
#include "common.h"
#include <stack>

using namespace std;


//recursion version
// bool hasPathSum(TreeNode* root, int sum) {
//     if (root == NULL) return false;
//     if (root->val == sum && root->left == NULL && root->right == NULL) return true;
//     else return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
// }


//non recursive version
bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    stack<TreeNode*> s;
    TreeNode* cur;
    TreeNode* last;
    cur = root;
    int running_sum = 0;
    while (cur != NULL || !s.empty()) {
        if (cur != NULL) {
            s.push(cur);
            running_sum += cur->val;
            cur = cur->left;
        }
        else {
            cur = s.top();
            if (cur->left == NULL && cur->right == NULL && running_sum == sum) return true;
            if (cur->right != NULL && last != cur->right) {
                cur = cur->right;
            }
            else {
                s.pop();
                running_sum -= cur->val;
                last = cur;
                cur = NULL;
            }
        }
    }

    return false;
}


int main() {
    int num[] = {5, 4, 8, 11, -99999, 13, 4, 7, 2, -99999, -99999, -99999, -99999, -99999, 1};
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    cout << "travel tree" << endl;
    travel(root);

    cout << "zigzag output" << endl;
    if (hasPathSum(root, 22)) cout << "true" << endl;
    else cout << "false" << endl;


    return 0;
}