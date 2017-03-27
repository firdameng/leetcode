/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *new_head = NULL, *np, *pre, *p = head;
    int flag = 0;
    if(head == NULL || head->next == NULL)
        return head;
    
    while(p)
    {
        if(head->val < x)               //首部结点移除到小于x的部分
        {
            head = head->next;
            if(!flag++)
                new_head = p;
            else
                np->next = p;
            np = p;
            p->next = NULL;
            p = head;
            
        }
        else
        {
            if(p->val < x)
            {
                pre->next = p->next;        //非首部结点移除到小于x的部分
                if(!flag++)
                    new_head = p;
                else
                    np->next = p;
                np = p;
                p->next = NULL;
                p = pre->next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
            
        }
    }
    if(new_head == NULL)            //链表中值均大于x
        return head;
    np->next = head;
    return new_head;
}