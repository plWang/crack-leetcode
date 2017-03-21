#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTreeByLevelOrder(vector<int> array, int n, int sub) {
    if (sub>=n) return NULL;
    if (array[sub] == -99999) return NULL;

    TreeNode* t = new TreeNode(array[sub]);

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
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}