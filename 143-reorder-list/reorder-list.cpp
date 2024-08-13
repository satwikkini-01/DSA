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
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* prev = NULL, *curr = slow -> next;
        while(curr){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        slow -> next = NULL;

        ListNode* first = head, *second = prev;
        while(second){
            ListNode* temp1 = first -> next, *temp2 = second -> next;
            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};