#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTreesCore(int begin, int end) {
    vector<TreeNode*> result;
    if (begin > end) {
        result.push_back(NULL);
        return result;
    }

    for (int i=begin; i<= end; i++) {
        vector<TreeNode*> left = generateTreesCore(begin, i-1);
        vector<TreeNode*> right = generateTreesCore(i+1, end);
        for (int j=0; j<left.size(); j++) {
            for (int k=0; k<right.size(); k++) {
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                result.push_back(root);
            }
        }
    }

    return result;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return vector<TreeNode*>();
    vector<TreeNode*> result = generateTreesCore(1, n);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> result = generateTrees(n);

    return 0;
}