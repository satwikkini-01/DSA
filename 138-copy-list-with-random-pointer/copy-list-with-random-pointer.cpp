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
        unordered_map<Node*,Node*>mpp;
        Node* cloneHead = NULL, *cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        Node* temp2 = cloneHead;
        temp = head;
        while(temp!=NULL){
            mpp[temp] = temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        temp = head;
        temp2 = cloneHead;
        while(temp!=NULL){
            temp2->random = mpp[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return cloneHead;
    }
};