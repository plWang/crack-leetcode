#include <queue>
#include <stack>
#include <iostream>
#include "common.h"

using namespace std;

vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > result;
    if (!root) return result;

    queue<TreeNode*> * currLevel = new queue<TreeNode*>;
    queue<TreeNode*> * nextLevel = new queue<TreeNode*>;
    stack<vector<int> > s;
    TreeNode* curr;
    currLevel->push(root);
    while (!currLevel->empty()) {
        vector<int> levelValues;
        while(!currLevel->empty()) {
            curr = currLevel->front();
            currLevel->pop();
            
            if (!curr) continue;
            levelValues.push_back(curr->val);
            if (curr->left) nextLevel->push(curr->left);
            if (curr->right) nextLevel->push(curr->right);
        }
        queue<TreeNode*> * tmp = currLevel;
        currLevel = nextLevel;
        nextLevel = tmp;
        s.push(levelValues);
    }
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
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
    vector<vector<int> > result = levelOrderBottom(root);
    for (int i=0; i<result.size(); i++) {
        vector<int> a = result[i];
        cout << "[";
        for (int j=0; j<a.size(); j++)
            cout << a[j] << " ";
        cout << "]" << endl;
    }


    return 0;
}