/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *p = head;
    int len = 0;
    while(p)
    {
        p = p->next;
        len++;
    }
    if(len < k)
        return head;
    p = head;
    struct ListNode *next = p->next, *new_head, *new_tmp_head, *new_end;
    int count = 0, flag = 0;
    new_head = new_tmp_head = new_end = NULL;
    while(p)
    {
        next = p->next;
        if(count == 0)      //记下k部分链表尾结点
            new_end = p;
        if(!new_head)       //不带头结点头插法
        {
            p->next = new_tmp_head;
            new_tmp_head = p;
        }
        else                //带头结点头插法
        {
            p->next = new_tmp_head->next;
            new_tmp_head->next = p;
        }
        
        count++;
        if(count == k)
        {
            if(!flag++)     //首次满k,即为新头结点
                new_head = new_tmp_head;
            count = 0;
            new_tmp_head = new_end;
            len -= k;       //若剩余结点小于k,则原状返回        
            if(len < k)
            {
                new_tmp_head->next = next;
                return new_head;
            }
        }
        p = next;
    }
    return new_head;
}
