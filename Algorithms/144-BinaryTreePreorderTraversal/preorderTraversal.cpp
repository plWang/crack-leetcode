// Solution 1: recursive
void preorderTraversalCore(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    result.push_back(root->val);
    preorderTraversalCore(root->left, result);
    preorderTraversalCore(root->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    //if (root == NULL) return result;
    preorderTraversalCore(root, result);

    return result;
}

// solution 2: iterative
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result; 
    if (root == NULL) return result;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* cur = s.top();
        result.push_back(cur->val);
        s.pop();
        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);
    }

    return result;
}