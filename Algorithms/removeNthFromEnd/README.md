####　Problem
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

#### 解题思路
本题应该采用双指针的解法。先让一个指针前进n步,然后两个指针同时移动，知道前面的指针到达最后。

注意两种特殊情况：
1. 链表长度为1，去掉倒数第1个数时，返回链表应该为空。
2.　要删去的元素是链表头时，需要特别考虑。