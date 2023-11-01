/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* ins = new Node(d);
        if(head == NULL){
            head = ins;
            tail = ins;
            return;
        }
        tail->next = ins;
        tail = ins;
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL, *cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        temp = head;
        Node* temp2 = cloneHead;
        Node* prev1 = NULL,*prev2 = NULL;
        while(temp!=NULL){
            prev1 = temp->next;
            temp->next = temp2;
            prev2 = temp2->next;
            temp2->next = prev1;
            temp = prev1;
            temp2 = prev2;
        }
        temp = head;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            else temp->next->random = NULL;
            temp = temp->next->next;
        }
        temp = head;
        temp2 = cloneHead;
        while(temp!=NULL && temp2!=NULL){
            temp->next = temp2->next;
            temp = temp->next;
            if(temp!=NULL) temp2->next = temp->next;
            temp2=temp2->next;
        }
        return cloneHead;
    }
};