#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution 1: 使用递归的中序遍历，用一个全局变量保存之前的节点
// TreeNode* pre = NULL; // 储存当前节点之前遍历的节点

// bool isValidBST(TreeNode* root) {
//     if (root == NULL) return true;

//     if (!isValidBST(root->left)) return false;
//     if (pre != NULL && root->val <= pre->val) // BST中序遍历序列是一个递增的序列，如果不满足递增条件，那么return false
//         return false;

//     prev = root;
//     return isValidBST(root->right);
// }


// Solution 2: iterative solution
bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    stack<TreeNode*> s;
    while (!s.empty() || cur) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        }
        else {
            cur = s.top();
            s.pop();
            if (pre != NULL && cur->val <= pre->val)
                return false;
            pre = cur;
            cur = cur->right;
        }
    }

    return true;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    if (isValidBST(root))
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}