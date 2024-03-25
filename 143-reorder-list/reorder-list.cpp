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
        stack<int>s1;
        queue<int>s2;
        ListNode* temp = head;
        while(temp != NULL){
            s1.push(temp->val);
            s2.push(temp->val);
            temp = temp -> next;
        }
        temp = head;
        int count = 0;
        while(temp != NULL){
            if(count % 2 == 0){
                count++;
                temp -> val = s2.front();
                s2.pop();
                temp = temp -> next;
                continue;
            }
            temp -> val = s1.top();
            s1.pop();
            temp = temp -> next;
            count++;
        }
    }
};