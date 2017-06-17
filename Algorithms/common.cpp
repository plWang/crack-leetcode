#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTreeByLevelOrder(vector<int> array, int n, int sub) {
    if (sub>=n) return NULL;
    TreeNode* t = new TreeNode(0);
    if (array[sub] == -99999) return NULL;

    t->val = array[sub];
    t->left = NULL;
    t->right = NULL;

    t->left = createTreeByLevelOrder(array, n, 2*sub+1);
    t->right = createTreeByLevelOrder(array, n, 2*sub+2);

    return t;
}

void travel(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == NULL) cout << "null" << " ";
        else {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
}

int main() {
    int num[] = {3, 9, 20, -99999, -99999, 15, 7};
    // use iterator constructor to construct vector
    vector<int> array (num, num+sizeof(num)/sizeof(int));
    
    vector<int>::iterator it;
    for (it=array.begin(); it!=array.end(); it++)
        cout << *it << " ";
    cout << endl;

    TreeNode* root = createTreeByLevelOrder(array, array.size(), 0);
    travel(root);
    return 0;
}