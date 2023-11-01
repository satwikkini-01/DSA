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
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode* ans = new ListNode(-1);
        ListNode* ansHead = ans;
        ListNode* temp1 = head1, * temp2 = head2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                ans->next = temp1;
                ans=ans->next;
                temp1=temp1->next;
            }
            else{
                ans->next = temp2;
                ans=ans->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            ans->next = temp1;
            ans=ans->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            ans->next=temp2;
            ans=ans->next;
            temp2=temp2->next;
        }
        return ansHead->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow = head,*fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* result = merge(left,right);
        return result;
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};