TreeNode* buildTreeCore(vector<int>& postorder, int p_s, int p_e, vector<int>& inorder, int i_s, int i_e) {
    if (p_s > p_e || i_s > i_e) return NULL;
    if (p_s == p_e || i_s == i_e) {
        TreeNode* root = new TreeNode(postorder[p_s]);
        return root;
    }

    int rootVal = postorder[p_e];
    int i;
    for (i=i_s; i<=i_e && inorder[i] != rootVal; i++);
    int left_len = i-i_s, right_len = i_e-i;
    
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeCore(postorder, p_s, p_s+left_len-1, inorder, i_s, i-1);
    root->right = buildTreeCore(postorder, p_s+left_len, p_e-1, inorder, i+1, i_e);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* root = buildTreeCore(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
}