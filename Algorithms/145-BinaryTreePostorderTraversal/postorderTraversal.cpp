//Solution 1: recursive
void postorderTraversalCore(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    postorderTraversalCore(root->left, result);
    postorderTraversalCore(root->right,result);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorderTraversalCore(root, result);
    return result;
}


// Solution 2: iterative
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;
    stack<TreeNode*> nodeStack;
    //nodeStack.push(root);
    TreeNode* cur = root;
    TreeNode* last = NULL;
    while (!nodeStack.empty() || cur) {
        if (cur != NULL) {
            nodeStack.push(cur);
            cur = cur->left;
        }
        else {
            cur = nodeStack.top();
            if (cur->right && cur->right != last) {
                cur = cur->right;
            }
            else {
                nodeStack.pop();
                result.push_back(cur->val);
                last = cur;
                cur = NULL;
            }
        }
    }

    return result;
}