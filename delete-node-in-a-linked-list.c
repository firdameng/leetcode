/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 void swap(int *a,int *b)
 {
     int t = *a;
     *a = *b;
     *b = t;
 }
 
void deleteNode(struct ListNode* node) {
    
    swap(&(node->val),&(node->next->val));
    
    if(node->next->next == NULL)
    {
        free(node->next);
        node->next = NULL;
    }
    else
    {
        struct ListNode *p = node->next;
        node->next = p->next;
        free(p);
    }
}