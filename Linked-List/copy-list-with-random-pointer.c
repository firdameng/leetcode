/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *p = head, *new_head = NULL,*np;
    int flag = 0;
    while(p)
    {
        struct RandomListNode *t = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        t->label = p->label;
        t->next = p->next;
        t->random = p->random;
        if(!flag++)                  //注意首结点
            new_head = t;
        else
            np->next = t;
        
        np = t;
        p = p->next;
    }
    np = new_head;              //根据label双重扫描新链表，并替换random
    
    while(np)
    {
        p = new_head;
        if(np->random != NULL)    //random指针为空时不考虑
        {
            while(p != NULL && np->random->label != p->label)
                p = p->next;
            if(p != NULL)
                np->random = p;
        } 
        np = np->next;
    }
    return new_head;
}