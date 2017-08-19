struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* head) {
    if (head == NULL) return NULL;
    RandomListNode* p = head;
    // 复制节点接在原节点后面
    while (p) {
        RandomListNode* q = new RandomListNode(p->label);
        q->next = p->next;
        p->next = q;
        p = p->next->next;
    }

    //设置Random指针
    p = head;
    while (p) {
        if (p->random) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }

    //将两段拆开
    p = head;
    RandomListNode* newHead = p->next;
    while (p) {
        RandomListNode* tmp = p->next;
        p->next = tmp->next;
        p = p->next;
        if (p)
            tmp->next = p->next;
    }

    return newHead;
}