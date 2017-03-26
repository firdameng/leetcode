/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    if(head == NULL)
        return false;
    struct ListNode *p = head, *q =head;
    do
    {
        q = q->next;
        p = p->next;
        if(p != NULL)               //判断是否往前走
            p = p->next;
    }while(p != q && p != NULL);    //有环或者走到结尾才跳出，注意互为逆否命题
    if(p == NULL)
        return false;
    return true;
}