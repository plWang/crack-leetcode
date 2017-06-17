#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* helper = new ListNode(0);

ListNode* merge(ListNode* left, ListNode* right) {
    helper->next = NULL;
    ListNode* p = helper;
    while (left || right) {
        if (left == NULL) {
            ListNode* tmp = right;
            right = right->next;
            tmp->next = NULL;
            p->next = tmp;
        }
        else if (right == NULL) {
            ListNode* tmp = left;
            left = left->next;
            tmp->next = NULL;
            p->next = tmp;
        }
        else if (left->val < right->val) {
            ListNode* tmp = left;
            left = left->next;
            tmp->next = NULL;
            p->next = tmp;
        }
        else {
            ListNode* tmp = right;
            right = right->next;
            tmp->next = NULL;
            p->next = tmp;
        }
        p = p->next;
    }

    return helper->next;
}

ListNode* sortListCore(ListNode* head, int length) {
    if (head->next == NULL) return head; // one element
    int i = 0;
    ListNode* p = head;
    while (i++ < length/2 - 1) {
        p = p->next;
    }
    ListNode* h2 = p->next;
    p->next = NULL;            // split the list
    ListNode* left = sortListCore(head, length/2);
    ListNode* right = sortListCore(h2, length-length/2);
    ListNode* result = merge(left, right);

    return result;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL) return NULL;
    int length = 0;
    ListNode* p = head;
    while (p) {
        length++;
        p = p->next;
    }
    ListNode * result = sortListCore(head, length);

    return result;
}

int main() {
    ListNode* pre = new ListNode(0);
    ListNode* p = pre;
    int n, tmp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        ListNode* q = new ListNode(tmp);
        p->next = q;
        p = p->next;
    }

    ListNode* result = sortList(pre->next);

}

// another solution : 
// instead of using recursive merge sort
// use bottom-up merge sort 