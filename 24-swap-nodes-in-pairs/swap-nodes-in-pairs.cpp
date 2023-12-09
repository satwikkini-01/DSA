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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head -> next)) return head;
        ListNode* n_head = new ListNode(0);
        n_head -> next = head;
        ListNode* prev = n_head, *curr = head;
        while(prev -> next != NULL && curr -> next != NULL){
            prev -> next = curr -> next;
            curr -> next = curr -> next -> next;
            prev -> next -> next = curr;
            prev = curr;
            curr = prev -> next;
        }
        return n_head -> next;
    }
};