/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    
    if(head == NULL)
        return NULL;

    if(head->next == NULL)
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = root->right = NULL;
        return root;
    }
        
    //双指针用于找出链表中间结点,slow,fast开始指向同一结点
    struct ListNode *slow = head, *fast = head, *pre = NULL;     //pre指针用于分割链表为两部分
    while(fast && fast->next != NULL)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;                               
    
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = slow->val;                  //slow即中间结点
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
    
}