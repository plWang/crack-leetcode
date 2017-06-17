bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode* slow = head->next;
    ListNode* fast = head->next->next;
    while (fast && fast->next && slow) {
        if (fast == slow) return true;
        fast = fast->next->next;
        slow = slow->next;
    }

    return false;
}