#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* ph = new ListNode(0);
    ListNode* q = ph;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            q->next = new ListNode(0);
            q = q->next;
            q->val = p1->val;
            p1 = p1->next;
        } 
        else {
            q->next = new ListNode(0);
            q = q->next;
            q->val = p2->val;
            p2 = p2->next;
        }
    }

    ListNode* r;
    if (p1 != NULL) {
        r = p1;
    }
    else {
        if (p2 == NULL) { 
            return ph->next;
        }
        else r = p2;
    }
    while (r != NULL) {
        q->next = new ListNode(0);
        q = q->next;
        q->val = r->val;
        r = r->next;
    }
    return ph->next;
}


int main() {
    ListNode* h1 = new ListNode(0);
    ListNode* p1 = h1;
    int len, a;
    cout << "Please input the length of the first list: ";
    cin >> len;
    cout << "Please Input the first list: " <<endl;
    cin >> a;
    p1->val = a;
    for (int i=0; i < len-1; i++) {
        cin >> a;
        p1->next = new ListNode(a);
        p1 = p1->next;
    }
    p1->next = NULL;

    ListNode* h2 = new ListNode(0);
    ListNode* p2 = h2;
    cout << "Please input the length of the second list: ";
    cin >> len;
    cout << "Please Input the second list: " <<endl;
    cin >> a;
    p2->val = a;
    for (int i=0; i < len-1; i++) {
        cin >> a;
        p2->next = new ListNode(a);
        p2 = p2->next;
    }
    p2->next = NULL;

    ListNode* h = mergeTwoLists(h1, h2);
    cout << "after transform" <<endl;
    while (h != NULL) {
        cout << h->val <<endl;
        h = h->next;
    }

    return 0;
}