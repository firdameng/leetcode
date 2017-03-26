/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head,*pre = NULL;
    if(head == NULL)
        return head;
    
    int len = 0;
    while(p)
    {
        p = p->next;
        len++;
    }
    if(n < 1 || n > len)
        return NULL;
    
    int k = len - n;
    p = head;
    while(k--)
    {
        pre = p;
        p = p->next;
    }
    if(pre != NULL)         //删除末尾及中间
        pre->next = p ? p->next : NULL;
    else
        head = p->next;     //删除开头
    free(p);                
    
    return head;
    
}