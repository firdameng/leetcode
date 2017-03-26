/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1, *p2 = l2,*np,*new_head;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    int flag = 0;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->val < p2->val)
        {
            if(!flag++)
                new_head = np = l1;         //给np初始化
            else
                np->next = p1;
            np = p1;
            p1 = p1->next;          
        }
        else
        {
            if(!flag++)
                new_head = np = l2;
            else
                np->next = p2;
            np = p2;
            p2 = p2->next;
        }
    }
    if(p1 == NULL)
        np->next = p2;
    if(p2 == NULL)
        np->next = p1;
    return new_head;
}