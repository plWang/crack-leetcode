#include <iostream>
#include "common.h"

using namespace std;


// Solution 1, recursive 

int depth (TreeNode *root) {
    if (root == NULL) return 0;
    return max (depth(root -> left), depth (root -> right)) + 1;
    }

bool isBalanced (TreeNode *root) {
    if (root == NULL) return true;
    
    int left=depth(root->left);
    int right=depth(root->right);
    
    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

//Solution 2 
int dfsHeight (TreeNode *root) {
    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return max (leftHeight, rightHeight) + 1;
}
bool isBalanced_dfs(TreeNode *root) {
    return dfsHeight (root) != -1;
}



int main() {
    int num[] = {1,2,2,3,-99999,-99999,3,4,-99999,-99999,-99999,-99999,-99999,-99999,-99999,-99999, 4};
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    cout << "travel tree" << endl;
    travel(root);

    cout << "zigzag output" << endl;
    if (isBalanced(root)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}