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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // A variable to store the length of the Linked List
        int len = 0;
        // A temporary Node starting from head
        ListNode* temp = head;
        // A loop to find the length of the Linked List
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }
        // A variable to store the position of the element that should be deleted
        int pos = len - n;
        // A temporary node starting from head
        ListNode* temp2 = head;
        // A variable to store the count to reach till the Node to be deleted
        int count=0;
        // A loop to reach till the node before the node to be deleted
        while(count<pos-1){
            temp2 = temp2 -> next;
            count++;
        }
        // Handling the edge case that is when the List has 1 element
        if(temp2 -> next == NULL) return NULL;
        if(pos == 0){
            head = head -> next;
        }
        // Deleting the node by connecting the prev node to the next node
        temp2 -> next = temp2 -> next -> next;
        return head;
    }
};