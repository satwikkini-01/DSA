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
    ListNode* merge(ListNode* ans, ListNode* temp) {
        if (!ans) return temp;
        if (!temp) return ans;

        ListNode dummy;
        ListNode* temp2 = &dummy;

        while (ans && temp) {
            if (ans->val <= temp->val) {
                temp2->next = ans;
                ans = ans->next;
            } else {
                temp2->next = temp;
                temp = temp->next;
            }
            temp2 = temp2->next;
        }

        if (ans) temp2->next = ans;
        if (temp) temp2->next = temp;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        if (n == 1) return lists[0];

        ListNode* ans = lists[0];
        for (int i = 1; i < n; ++i) {
            ans = merge(ans, lists[i]);
        }

        return ans;
    }
};