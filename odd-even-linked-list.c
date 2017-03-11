/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *even,*ep, *odd,*op, *p,*next;
    if(head == NULL || head->next == NULL ||head->next->next == NULL)
        return head;
    p = head->next->next;       //至少第三个
    odd = op = head;
    even = ep = head->next;
    
    odd->next = even->next = NULL;//初始化
    
    bool is_odd=true;
    while(p)
    {
        if(is_odd)
        {
            op->next = p;
            op = p;
        }
        else
        {
            ep->next = p;
            ep = p;
        }
        is_odd = !is_odd;
        
        next = p->next;
        if(next != NULL)        //有下一个结点时
            p->next = NULL;         //分割结点，防止环路
        p = next;
    }
    op->next = even;
    
    return odd;
}