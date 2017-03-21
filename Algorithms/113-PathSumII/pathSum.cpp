#include <iostream>
#include "common.h"
#include <stack>

using namespace std;

//non recursive version
vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > result;
    if (root == NULL) return result;
    stack<TreeNode*> s;
    TreeNode* cur;
    TreeNode* last;
    cur = root;
    vector<int> curPath;
    int running_sum = 0;
    while (cur != NULL || !s.empty()) {
        if (cur != NULL) {
            s.push(cur);
            curPath.push_back(cur->val);
            running_sum += cur->val;
            cur = cur->left;
        }
        else {
            cur = s.top();
            if (cur->left == NULL && cur->right == NULL && running_sum == sum) {
                result.push_back(curPath);
            }
            if (cur->right != NULL && last != cur->right) {
                cur = cur->right;
            }
            else {
                s.pop();
                running_sum -= cur->val;
                curPath.pop_back();
                last = cur;
                cur = NULL;
            }
        }
    }

    return result;
}


int main() {
    int num[] = {5, 4, 8, 11, -99999, 13, 4, 7, 2, -99999, -99999, -99999, -99999, 5, 1};
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    cout << "travel tree" << endl;
    travel(root);

    cout << "zigzag output" << endl;
    vector<vector<int> > result = pathSum(root, 22);
    for (int i=0; i<result.size(); i++) {
        vector<int> a = result[i];
        cout << "[";
        for (int j=0; j<a.size(); j++)
            cout << a[j] << " ";
        cout << "]" << endl;
    }


    return 0;
}