/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* r = head; 
            ListNode* l = nullptr;
        while(n--)
            r = r->next;
        // might be a case when n==sz of the list
        if(r==nullptr)
            return head->next;
        
        while(r)
        {
            r = r->next;
            if(l==nullptr)
                l = head;
            else
                l = l->next;
        }
        // if(l==nullptr)
            // head->next = head->next->next;
        
            l->next  = l->next->next;
        
        return head;
        
        
    
    }
};