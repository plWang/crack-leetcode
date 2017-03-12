#include <iostream>
#include "common.h"

using namespace std;

int minDepth(TreeNode* root) {
    queue<TreeNode*> q;
    if (root == NULL) return 0;
    q.push(root);
    int minDepth = 0;
    TreeNode* curr;
    while (!q.empty()) {
        int n = q.size();
        minDepth++;
        for (int i=0; i<n; i++) {
            curr = q.front();
            q.pop();
            if (curr->left == NULL && curr->right == NULL) return minDepth;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    return minDepth;
}

int main() {
    int num[] = {3, 9, 20, -99999, -99999, 15, 7};
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    cout << "travel tree" << endl;
    travel(root);

    cout << "zigzag output" << endl;
    int d = minDepth(root);
    cout << d << endl;


    return 0;
}