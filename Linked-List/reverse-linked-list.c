/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //递归版
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *tail;
    if(head == NULL || head->next == NULL)
        return head;
    tail = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tail;
}