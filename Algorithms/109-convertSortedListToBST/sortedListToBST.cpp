#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

 

TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        root = new ListNode(head->val);
        return root;
    }
    int len = 0;
    ListNode* p1 = head;
    ListNode* p2 = head;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    while (p1 && p2 && p2->next) {
        p1 = p1->next;
        pre = pre->next;
        p2 = p2->next->next;
        len++;
    }

    pre->next = NULL;
    TreeNode* root = new TreeNode(p1->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(p1->next);

    return root;

}

int main() {
    ListNode* head = new ListNode(0);
    TreeNode* root = sortedListToBST(head);
    return 0;
}