/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *pre, *np = NULL, *new_head;
    bool is_even = true;
    int flag = 0;
    
    if(head == NULL || head->next == NULL)
        return head;
        
    pre = head;
    p = head->next;
    while(p)
    {
        if(is_even)
        {
            if(!flag++)
                new_head = p;
            pre->next = p->next;
            p->next = pre;
            if(np != NULL)          //np不为空，两步骤，先调整更新np指向新调整后的首结点，再np后移
                np->next = p;
            np = p;                 //np为空or不为空时，都得后移即走向p
            p = pre->next;
        }
        else
        {
            
            if(np != NULL)
                np = np->next;
            pre = p;
            p = p->next;
        }
        is_even = !is_even;
    }
    
    return new_head;
    
}