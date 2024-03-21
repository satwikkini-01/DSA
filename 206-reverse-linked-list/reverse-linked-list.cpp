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

    void insertAtHead(ListNode* &head, int d){
        //new node create
        ListNode* temp = new ListNode(d);
        temp -> next = head;
        head = temp;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* ans = new ListNode(head->val);
        ListNode* temp = head -> next;
        while(temp != NULL){
            insertAtHead(ans,temp->val);
            temp = temp -> next;
        }
        return ans;
    }
};