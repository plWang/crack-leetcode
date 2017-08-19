// 后序遍历

TreeNode* flatternCore(TreeNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return root;
    if (root->left) TreeNode* l = faltternCore(root->left);
    if (root->right) TreeNode* r = flatternCore(root->right);
    root->left = NULL;
    root->right = l;
    TreeNode* p = root;
    while (p->right != NULL)
        p = p->right;
    p->right = r;

    return root;
}

void flattern(TreeNode* root) {
    TreeNode* newroot = flatternCore(root);
}