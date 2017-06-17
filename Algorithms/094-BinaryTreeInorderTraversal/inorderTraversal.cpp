//Solution 1: recursive
void inorderTraversalCore(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    result.push_back(root->val);
    inorderTraversal(root->left, result);
    inorderTraversal(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderTraversalCore(root, result);
    return result;
}


// Solution 2: iterative
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;

    stack<TreeNode*> s;
    TreeNode* cur = root;
    while (!s.empty() || cur) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        }
        else {
            cur = s.top();
            s.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }

    return result;
}