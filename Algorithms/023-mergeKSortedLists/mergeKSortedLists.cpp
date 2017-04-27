#include <iostream>

using namespace std;


ListNode* mergeKLists(vector<ListNode*> &lists) {
    vector<ListNode*> mins;
    int k = lists.size();
    int count = 0;
    for (int i=0; i<k; i++) {
        ListNode* tmp = lists[i];
        mins.push_back(tmp);
        if (!tmp) count++;
    }
    
    ListNode* minNode;
    ListNode* res;
    ListNode* pre = new ListNode(0);
    ListNode* root = pre;
    while (count < k) {
        ListNode* cur;
        int minVal = 1000, minIdx = -1;
        for (int i=0; i<k; i++) {
            if (mins[i] && mins[i]->val < minVal) {
                minNode = mins[i];
                minVal = minNode->val;
                minIdx = i;
            }
        }
        mins[minIdx] = mins[minIdx]->next;
        cur = new ListNode(minVal);
        pre->next = cur;
        pre = pre->next;
        if (!mins[minIdx]) count++;
    }

    return root->next;
}

int main() {
    return 0;
}