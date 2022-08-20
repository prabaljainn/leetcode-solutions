/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode * head;

    ListNode* reverseList(ListNode *root)
    {
        if(root==NULL)
            return NULL;
        
        if (root->next == NULL)
        {
            head = root;
  
            return head;
        }
        reverseList(root->next);
        root->next->next = root;
        root->next = NULL;
        return head;
    }
};