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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL){
            if(slow -> next != NULL) slow = slow -> next;
            if(fast -> next != NULL && fast -> next -> next != NULL) fast = fast -> next -> next;
            else break;
        }
        return slow;
    }
};