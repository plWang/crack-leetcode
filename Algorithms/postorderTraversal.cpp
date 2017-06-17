#include <iostream>
#include "common.h"
#include <vector>
#include <queue>
#include <stack>

void postOrder(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> s;
    TreeNode* cur;
    cur = root;
    TreeNode* last = NULL;
    while (cur != NULL || !s.empty()) {
        if (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        else {
            cur = s.top();
            if (cur->right != NULL && cur->right != last) {
                cur = cur->right;
            }
            else {
                s.pop();
                cout << cur->val << endl;
                last = cur;
                cur = NULL;
            }
        }
    }
}

int main() {
    int num[] = {3, 9, 20, 15, 7, -99999, -99999, -99999, 1, 2, -99999 };
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    cout << "travel tree" << endl;
    travel(root);

    cout << "zigzag output" << endl;
    postOrder(root);


    return 0;
}