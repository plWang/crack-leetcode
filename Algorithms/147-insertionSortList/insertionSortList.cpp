#include <iostream>

#define INT_MIN -90000000

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode* helper = new ListNode(INT_MIN);
    helper->next = NULL;
    ListNode* cur = head;
    while (cur) {
        ListNode* p = helper;
        while (p->next) {
            if (p->next->val > cur->val) break;
            p = p->next;
        }
        ListNode* tmp1 = p->next;
        ListNode* tmp2 = cur->next;
        p->next = cur;
        p->next->next = tmp1;
        cur = tmp2;
    }

    return helper->next;
}

int main() {
    ListNode* p1 = new ListNode(5);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    p1->next = p2;
    p2->next = p3;
    ListNode* result = insertionSortList(p1);

    return 0;
}