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
        ListNode* head1 = ans;
        while(list1 && list2){
            if(list1 -> val < list2 -> val){
                ListNode* temp = new ListNode(list1 -> val);
                ans -> next = temp;
                list1 = list1 -> next;
            }
            else{
                ListNode* temp = new ListNode(list2 -> val);
                ans -> next = temp;
                list2 = list2 -> next;
            }
            ans = ans -> next;
        }
        while(list1){
            ListNode* temp = new ListNode(list1 -> val);
            ans -> next = temp;
            list1 = list1 -> next;
            ans = ans -> next;
        }
        while(list2){
            ListNode* temp = new ListNode(list2 -> val);
            ans -> next = temp;
            list2 = list2 -> next;
            ans = ans -> next;
        }
        return head1 -> next;
    }
};