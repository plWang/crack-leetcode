TreeNode* buildTreeCore(vector<int>& preorder, int p_s, int p_e, vector<int>& inorder, int i_s, int i_e) {
    if (p_s > p_e || i_s > i_e) return NULL;
    if (p_s == p_e || i_s == i_e) {
        TreeNode* root = new TreeNode(preorder[p_s]);
        return root;
    }

    int rootVal = preorder[p_s];
    int i;
    for (i=i_s; i<=i_e && inorder[i] != rootVal; i++);
    int left_len = i-i_s, right_len = i_e-i;
    
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeCore(preorder, p_s+1, p_s+left_len, inorder, i_s, i-1);
    root->right = buildTreeCore(preorder, p_s+left_len+1, p_e, inorder, i+1, i_e);

    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = buildTreeCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    return root;
}