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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* t = ans;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 && t2){
            if(t1 -> val > t2 -> val){
                ListNode* tmp = new ListNode(t2 -> val);
                t -> next = tmp;
                t = t -> next;
                t2 = t2 -> next;
            }
            else{
                ListNode* tmp = new ListNode(t1 -> val);
                t -> next = tmp;
                t = t -> next;
                t1 = t1 -> next;
            }
        }
        while(t1){
            ListNode* tmp = new ListNode(t1 -> val);
            t -> next = tmp;
            t = t -> next;
            t1 = t1 -> next;
        }
        while(t2){
            ListNode* tmp = new ListNode(t2 -> val);
            t -> next = tmp;
            t = t -> next;
            t2 = t2 -> next;
        }
        return ans -> next;
    }
};