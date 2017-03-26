/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //时间复杂度 O（n^2）
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *p = head->next, *next;
    struct ListNode *new_head, *t_pre, *t_p,*np;
    new_head = np = head;
    new_head->next = NULL;
    
    while(p)
    {
        next = p->next;
        if(p->val >= np->val)        //大于或等于有序新链表最大值
        {
            
            p->next = NULL;
            np->next = p;
            np = p;
            
        }
        else
        {
            
            if( p->val <= new_head->val) //小于或等于有序新链表最小值
            {
               
                p->next = new_head;
                new_head = p;
                
            }
            else                        //在有序新链表中间
            {
                t_pre = t_p = new_head;
                while(t_p)
                {
                   if(t_p->val > p->val)   //只需要大于，等于没必要 
                   {
                      p->next = t_p;
                      t_pre->next = p;
                      break;
                   }
                   t_pre = t_p;       //必须要从头走过来，否则记不住t_pre
                   t_p = t_p->next;   
                }
            }
        }
        p = next;
    }
    return new_head;
}
