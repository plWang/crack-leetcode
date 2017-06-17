#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || m == n) return head;
    ListNode* p = head;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    int count = 1;
    while (count++ < m) {
        p = p->next;
        pre = pre->next;
    }
    ListNode* ahead = pre;
    ListNode* tail = p;

    pre = pre->next;
    p = p->next;
    //count++;

    while (count <= n ) {
        ListNode* tmp = p->next;
        p->next = pre;
        pre = p;
        p = tmp;
        count++;
    }

    ahead->next = pre;
    tail->next = p;
    if (tail == head) return ahead->next;
    else return head;
}

int main() {
    ListNode* p1 = new ListNode(3);
    ListNode* p2 = new ListNode(5);
    p1->next = p2;
    reverseBetween(p1, 1,2);
}