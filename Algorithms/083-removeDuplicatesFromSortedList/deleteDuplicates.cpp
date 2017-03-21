#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* p = head;
    int num;
    if (head == NULL || head->next == NULL) return head;
    else {
        num = p->val;
        p = p->next;
        pre = pre->next;
    }
    while (p != NULL) {
        if (p->val == num) {
            pre->next = p->next;
            p = p->next;
        }
        else {
            num = p->val;
            p = p->next;
            pre = pre->next;
        }
    }
    return head;
}

int main() {
    ListNode head(0);
    ListNode* p = &head;
    int len;
    int a;
    cout << "Please input the length of list" << endl;
    cin >> len;
    cout << "Now input the list: " << endl;
    cin >> a;
    p->val = a;
    for (int i=0; i < len-1; i++) {
        cin >> a;
        p->next = new ListNode(a);
        p = p->next;
    }
    p->next = NULL;

    ListNode* h = deleteDuplicates(&head);

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