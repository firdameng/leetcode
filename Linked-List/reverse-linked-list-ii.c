/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *p = head, *next, *start, *end;
    int count = 1;
    
    if(head == NULL || head->next == NULL || m >= n)
        return head;
    if(m == 1)
    {
        head = NULL;
        
    }
    else
    {
        while(count++ < m - 1) p = p->next;
        start = p; 
        p = p->next;
        start->next = NULL;
    }
    end = p;
    count = 1;
    while(count++ <= n - m + 1 )
    {
        next = p->next;
        if(m == 1)              //不带头结点头插法
        {
            p->next = head;
            head = p;
        }
        else
        {
            p->next = start->next;
            start->next = p;
        }
        p = next;
    }
    end->next = p;
    return head;
}
