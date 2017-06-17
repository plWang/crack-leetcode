ListNode* partition(ListNode* head) {
    ListNode* p1 = new ListNode(0);
    ListNode* p2 = new ListNode(0);
    ListNode* left = p1;
    ListNode* right = p2;
    while (head) {
        if (head->val < 3) {
            p1->next = head;
            p1 = p1->next;
        }
        else {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }

    p2->next = NULL;
    p1->next = right->next;

    return left->next;
}