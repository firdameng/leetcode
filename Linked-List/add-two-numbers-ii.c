/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    int len1 = 0,len2 = 0;
    struct ListNode *p1 = l1, *p2 = l2, *head=NULL;
    while(p1)
    {
        len1++;
        p1 = p1->next;
    }
    while(p2)
    {
        len2++;
        p2 = p2->next;
    }
    int max,min;
    struct ListNode *pmax,*pmin;        //找出链表长度大的
    if(len1 >= len2)
    {
        max = len1;
        min =len2;
        pmax = l1;
        pmin = l2;
    }
    else
    {
        max = len2;
        min =len1;
        pmax = l2;
        pmin = l1;
    }
    
    for(int i = 0; i<max; i++)          //构建临时结果链表
    {
        int result;
        if(i < max-min)
            result = pmax->val;
        else
        { 
            result = pmax->val + pmin->val;
            pmin = pmin->next;
        }
        pmax = pmax->next;
        
        struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
        t->val = result;
        t->next = head;   
        head = t;
    }
    struct ListNode *p = head,*pre;     
    int r,c=0;
    while(p)                            //逐位计算
    {
        r = (p->val +c)%10;
        c = (p->val +c)/10;
        p->val = r;
        pre = p;
        p = p->next;
    }
    if(c != 0)                          //关键要考虑到首位还有进位
    {
        struct ListNode * t = (struct ListNode *)malloc(sizeof(struct ListNode));
        t->val = c;
        t->next = NULL;
        pre->next = t;
    }
    
    p = head;
    head = NULL;
    struct ListNode *next;
    while(p)                            //逆序
    {
        next = p->next;
        p->next = head;
        head = p;
        p = next;
    }
    return head;
    
}