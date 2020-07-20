//Remove Linked List Elements
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 *     ListNode *r;  
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
     
        while(head!=NULL && head->val == val)  head = head->next;
        if(head==NULL)  return NULL;
          
        ListNode* NewHead = head;
        while(head->next!=NULL)
            if(head->next->val== val)  head->next = head->next->next;
            else        head = head->next;

        return NewHead;
    }
};
