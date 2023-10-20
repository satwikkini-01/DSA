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
    ListNode* rev1(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = NULL;
        while(curr != NULL){
            fwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head,*entry=head;
        if(fast->next==NULL) return true;
        if(fast->next->next==NULL){
            if(fast->val == fast->next->val) return true;
            return false;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = rev1(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(slow->val != entry->val) return false;
            slow=slow->next;
            entry=entry->next;
        }
        return true;
    }
};