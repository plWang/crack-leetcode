#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* p = head;
    ListNode* q = head;
    ListNode* newHead = new ListNode(0);
    ListNode* helper = newHead;
    while (p && q) {
        while (q && p->val == q->val) {
            q = q->next;
        }
        if (p->next == NULL || (q && p->next == q)) {
            helper->next = p;
            p->next = NULL;
            helper = helper->next;
        }
        p = q;
    }

    return newHead->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new
    ListNode* result = deleteDuplicates(head);

}