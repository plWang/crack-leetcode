#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1;
    ListNode* res = new ListNode(0);
    ListNode* pre = res;
    p1 = head;
    pre->next = head;
    for (int i=0; i < n-1 && p1->next !=NULL; i++) {
        p1 = p1->next;
    }
    if (p1->next == NULL && p1 == head) return NULL; 
    
    while (p1->next != NULL) {
        p1 = p1->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    return res->next;
}

int main() {
    ListNode head(0);
    ListNode* p = &head;
    ListNode* q = &head;
    int len;
    int a;
    cout << "Please input the length of list" << endl;
    cin >> len;
    cout << "Now input the list: " << endl;
    cin >> a;
    p->val = a;
    cout << "next" << endl;
    for (int i=0; i < len-1; i++) {
        cin >> a;
        p->next = new ListNode(a);
        p = p->next;
        cout << "next" <<endl;
    }
    p->next = NULL;

    cout << "the list looks like: " << endl;
    ListNode* p1 = q;
    while (p1->next != NULL) {
        cout << p1->val << endl;
        p1 = p1->next;
    }
    cout << p1->val << endl;

    int n;
    cout << "Now input the index you want to remove from the end: ";
    cin >> n;
    ListNode* h = removeNthFromEnd(q, n);

    cout << "after transform" <<endl;
    if (h == NULL) cout << "NULL" << endl;
    else {
        while (h->next != NULL) {
            cout << h->val <<endl;
            h = h->next;
        }
        cout << h->val << endl;
    }
    return 0;
}