#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head) {
    ListNode* p = head;
    if (head == NULL || head->next == NULL) return head;

    ListNode* tmp;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* res = pre;
    
    while (p != NULL) {
        // odd number
        if (p->next == NULL) return res->next;
        else {
            tmp = p->next;
            p->next = p->next->next;
            tmp->next = p;
            pre->next = tmp;
            
            if (p->next == NULL) return res->next;
            else {
                pre = p;
                p = p->next;
            }
        }
    }

    return res->next;
}

int main() {
    ListNode* h = new ListNode(0);
    ListNode* p = h;
    int len, a;
    cout << "Please input the length of the list: ";
    cin >> len;
    cout << "Please Input the list: " <<endl;
    cin >> a;
    p->val = a;
    for (int i=0; i < len-1; i++) {
        cin >> a;
        p->next = new ListNode(a);
        p = p->next;
    }
    p->next = NULL;

    ListNode* res = swapPairs(h);
    cout << "after transform" <<endl;
    while (res != NULL) {
        cout << res->val <<endl;
        res = res->next;
    }

    return 0;
}