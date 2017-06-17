// Solution 1: iterative solution, preorder traversal
// but it will change the value of tree
int sumNumbers(TreeNode* root) {
    if (root == NULL) return 0;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* cur;
    int sum = 0;
    while (!s.empty()) {
        cur = s.top();
        s.pop();
        if (cur->right != NULL) {
            cur->right->val = cur->val * 10 + cur->right->val;
            s.push(cur->right);
        }

        if (cur->left != NULL) {
            cur ->left->val = cur->val * 10 + cur->left->val;
            s.push(cur->val);
        }

        if (cur->left == NULL && cur->right == NULL) {
            sum += cur->val;
        }
    }

    return sum;
}


// Solution 2: recursive solution
int sumNumbersCore(TreeNode* root, int val) {
    int sum = 0;
    if (root->left) {
        sum += sumNumbersCore(root->left, val*10+root->val);
    }

    if (root->right) {
        sum += sumNumbersCore(root->right, val*10+root->val);
    }

    if (root->left == NULL && root->right = NULL)
        sum += val*10+root->val;

    return sum;
}


int sumNumbers(TreeNode* root) {
    if (root == NULL) return 0;
    return sumNumbersCore(root, 0);
}