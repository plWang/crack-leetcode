#include <iostream>
#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* detectCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;
    
    ListNode* slow = head->next;
    ListNode* fast = head->next->next;
    bool isCycle = false;
    while (slow && fast && fast->next) {
        if (slow == fast) {
            isCycle = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if (!isCycle) return NULL;
    ListNode* p1 = head;
    ListNode* p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main() {
    ListNode* p1 = new ListNode(3);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(0);
    ListNode* p4 = new ListNode(-4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p2;
    ListNode* result = detectCycle(p1);
    return 0;
}