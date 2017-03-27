/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * 
 * palindrome pk cycle + 仔细看题呀，老铁
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *p = head,*q = head;
    
    if(head == NULL || head->next == NULL)
        return true;
        
    while(q && q->next)
    {
        p = p->next;
        q = q->next->next;
    }
    struct ListNode *next, *pL = NULL, *pMid = p, *pR = q == NULL ? p : p->next;
    p = head;
    while(p != pMid)
    {
        next = p->next;         //头插法，注意先暂存next结点
        p->next = pL;
        pL = p;
        p = next;
    }
    while(pR)
    {
        if(pL->val != pR->val)
            return false;
        pL = pL->next;
        pR = pR->next;
    }
    return true;
}