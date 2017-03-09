/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //迭代版
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pre = NULL, *cur = head, *next;
    if(head == NULL || head->next == NULL)
        return head;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;         //记录cur->next作用
    }
    return pre;
}