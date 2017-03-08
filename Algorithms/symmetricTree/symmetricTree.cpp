#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
    if (left == NULL || right == NULL) 
        return left==right;
    else if (left->val != right->val)
        return false;
    else
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}