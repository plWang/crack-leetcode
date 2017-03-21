#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* t1;
    TreeNode* t2;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
        t1 = q.front();
        q.pop();
        t2 = q.front();
        q.pop();
        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;
        if (t1->val != t2->val) return false;
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
}

int main() {
    TreeNode* root;

    return 0;
}
