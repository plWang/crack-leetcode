#include <iostream>
#include <queue>
#include "common.h"

using namespace std;


int maxDepth(TreeNode* root) {
    return root == NULL? 0: max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Bridth-firth version
int maxDepth_bf(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* curr;
    int depth = 0;
    int n;
    if (root == NULL) return 0;
    while (!q.empty()) {
        depth++;
        n = q.size();
        for (int i=0; i<n; i++) {
            curr = q.front();
            q.pop();
            if (curr == NULL) continue;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    };

    return depth;
}

int main() {
    TreeNode* root = new TreeNode(0);
    int depth = maxDepth_bf(root);
    cout << depth << endl;
}