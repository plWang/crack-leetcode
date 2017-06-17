ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || k == 0) return head;
    ListNode* ahead = head;
    ListNode* behind = head;
    int length = 0;
    while (ahead) {
        ahead = ahead->next;
        length++;
    }
    k = k%length;
    if (k == 0) return head;
    ahead = head;
    while (k--) ahead = ahead->next;
    
    while (ahead->next) {
        ahead = ahead->next;
        behind = behind->next;
    }
    ListNode* newHead = behind->next;
    behind->next = NULL;
    ahead->next = head;

    return newHead;
}