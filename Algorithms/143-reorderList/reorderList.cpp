#include <iostream>
#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
    deque<ListNode*> q;
    if (head == NULL) return;
    ListNode* p = head;
    while (p) {
        q.push_back(p);
        p = p->next;
    }

    ListNode* helper = new ListNode(0);
    while (!q.empty()) {
        ListNode* tmp = q.front();
        tmp->next = NULL;          // next指针设为空
        q.pop_front();
        helper->next = tmp;
        helper = helper->next;
        if (!q.empty()) {
            ListNode* tmp = q.back();
            tmp->next = NULL;
            q.pop_back();
            helper->next = tmp;
            helper = helper->next;
        }
    }

}

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    reorderList(p1);
}