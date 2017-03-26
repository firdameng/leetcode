/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /**
  * rotate the list to the right by k places 
  *  谷歌翻译：将链表向右旋转k个位置
  *  黑盒测试：将链表向左旋转k个位置
  * 
  *  [4] [3] [2] [1] [0]
  * 1 ->2 ->3 ->4 ->5
  * 
  * 
  * k=1,6时，5 ->1 ->2 ->3 ->4 
  * k=2,7时，4 ->5->1 ->2 ->3 
  * k=3,8时，3 ->4 ->5->1 ->2
  * k=4,9时，2 ->3 ->4 ->5->1 
  * k=5,10时，1 ->2 ->3 ->4 ->5
  * 
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    
    if(k < 0 || head == NULL)    //边界考虑很常见
        return NULL;
        
    int len = 0;
    struct ListNode *p = head,*pre = NULL,*new_head;

    while(p)
    {
        len++;
        p = p->next;
    }

    if(k%len == 0)              //k%len = 0,5,10
        return head;
        
    p = head;
    int count = 1;
    while(p)
    {
        if(count++ == len-k%len)    //k%len = 1,2,3,4
        {
            new_head = p->next;
            p->next = NULL;
            p = new_head;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    pre->next = head;
    return new_head;
}