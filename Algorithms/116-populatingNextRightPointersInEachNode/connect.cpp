//Solution 1: 层序遍历
// 但是题目要求只能使用常数的额外空间，所以这种方案不可行
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    queue<TreeLinkNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            TreeLinkNode* cur = q.front();
            q.pop();
            if (i < n-1) {
                cur->next = q.front();
            }
            else {
                cur->next = NULL;
            }
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
}

// Solution 2
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root, *cur;
    while (pre->left) {
        cur = pre;
        while (cur) {
            cur->left->next = cur->right;
            if (cur->next)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
} 