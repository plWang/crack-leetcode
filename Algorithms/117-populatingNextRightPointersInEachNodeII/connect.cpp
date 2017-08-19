void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *cur, *head=NULL, *prev=NULL;
    while (cur) {
        while (cur) {
            if (cur->left) {
                if (prev != NULL) {
                    prev->next = cur->left;
                }
                else {
                    head = cur->left;
                }
                prev = cur->left;
            }
            if (cur->right) {
                if (prev != NULL) {
                    prev->next = cur->right;
                }
                else {
                    head = cur->right;
                }
                prev = cur->right;
            }

            cur = cur->next;
        }
        cur = head;
        head = NULL;
        prev = NULL;
    }
} 