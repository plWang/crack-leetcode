#include <iostream>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // handle special event
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    int mod = 0;
    int start = 0;
    ListNode* root, pre;
    //
    while (l1 && l2) {
        ListNode * cur = new ListNode(0);
        int sum = l1->val + l2->val + mod;
        mod = sum / 10;
        cur->val = sum % 10;
        if (start == 0) {
            root = cur;
            pre = cur;
            start = 1;
        }
        else {
            pre->next = cur;
            pre = pre->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 == NULL && l2 == NULL && mod == 0) return root;
    ListNode* p;
    if (l1 || l2) {
        if (l1) p = l1;
        else p = l2;

        while (p) {
                ListNode * cur = new ListNode(0);
                int sum = p->val + mod;
                mod = sum / 10;
                cur->val = sum % 10;
                pre->next = cur;
                p = p->next;
                pre = pre->next;
        }
    }
    if (mod) { // l1 == NULL, l2 == NULL, mod == 1
        ListNode* cur = new ListNode(0);
        cur->val = mod;
        pre->next = cur;
    }

    return root;

}

int main() {
    return 0;
}