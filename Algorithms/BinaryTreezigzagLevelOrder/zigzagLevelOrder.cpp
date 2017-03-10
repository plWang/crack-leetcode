#include <iostream>
#include "common.h"
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if (!root) return result;
    stack<TreeNode*> *currLevel = new stack<TreeNode*>();
    stack<TreeNode*> *nextLevel = new stack<TreeNode*>();
    int reverse = 1;
    TreeNode* curr;
    currLevel->push(root);
    vector<int> row;
    while (!currLevel->empty()) {
        row.clear();
        while (!currLevel->empty()) {
            curr = currLevel->top();
            currLevel->pop();
            if (curr == NULL) continue;
            if (reverse == 1) {
                if (curr->left) nextLevel->push(curr->left);
                if (curr->right) nextLevel->push(curr->right);
            }
            else {
                if (curr->right) nextLevel->push(curr->right);
                if (curr->left) nextLevel->push(curr->left);
            }
            row.push_back(curr->val);
        }
        reverse *= -1;
        result.push_back(row);
        stack<TreeNode*> *tmp = currLevel;
        currLevel = nextLevel;
        nextLevel = tmp;
    }
    return result;
}

int main() {
    int num[] = {3, 9, 20, -99999, -99999, 15, 7};
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    cout << "travel tree" << endl;
    travel(root);

    cout << "zigzag output" << endl;
    vector<vector<int> > result = zigzagLevelOrder(root);
    for (int i=0; i<result.size(); i++) {
        vector<int> a = result[i];
        cout << "[";
        for (int j=0; j<a.size(); j++)
            cout << a[j] << " ";
        cout << "]" << endl;
    }


    return 0;
}
