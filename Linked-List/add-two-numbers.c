/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1, *p2 = l2, *pre1,*pre2;
    int r, c = 0;
    
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    while(p1 != NULL && p2 != NULL)
    {
        r = (p1->val + p2->val+ c) % 10;  //余数
        c = (p1->val + p2->val+ c) / 10;  //进位
        p1->val = r;
        
        pre1 = p1;
        pre2 = p2;
        p1 = p1->next;
        p2 = p2->next;
    }
    if(p1 == NULL && p2 != NULL)
    {
        pre1->next = p2;
        pre2->next = NULL;
        
        while(p2 != NULL && c != 0)
        {
            r = (p2->val+ c) % 10;  //余数
            c = (p2->val+ c) / 10;  //进位
            p2->val = r;
            pre2 = p2;
            p2 = p2->next;
        }
        if(c != 0)
        {
            struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
            t->val = c;
            t->next = NULL;
            pre2->next = t;
        }
    }
    else if(p2 == NULL && p1 != NULL)
    {
        while(p1 != NULL && c != 0)
        {
            r = (p1->val+ c) % 10;  //余数
            c = (p1->val+ c) / 10;  //进位
            p1->val = r;
            pre1 = p1;
            p1 = p1->next;
        }
        if(c != 0)
        {
            struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
            t->val = c;
            t->next = NULL;
            pre1->next = t;
        }
        
    }
    else 
    {
        if(c > 0)
       {
           struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
            t->val = c;
            t->next = NULL;
            pre1->next = t;
       }
    }
    p2 = l2;
    while(p2 != NULL)
    {
        struct ListNode *t = p2;
        p2 = p2->next;
        free(t);
    }
    
    return l1;
}