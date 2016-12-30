#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) {
        if (p == NULL && q == NULL) return true;
        else return false;
    }
    else return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {
    TreeNode* p = new TreeNode(1);
    TreeNode* pleft = new TreeNode(2);
    TreeNode* pright = new TreeNode(3);
    p->left = pleft;
    p->right = pright;

    TreeNode* q = new TreeNode(1);
    TreeNode* qleft = new TreeNode(2);
    TreeNode* qright = new TreeNode(3);
    q->left = qleft;
    q->right = qright;

    if (isSameTree(p, q)) cout << "True" << endl;
    else cout << "False" << endl;
}