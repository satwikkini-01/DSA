/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void cnt(TreeNode* root, vector<int>& ans){
        if(!root) return;
        ans.push_back(root -> val);
        cnt(root -> left, ans);
        cnt(root -> right, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        cnt(root, ans);
        sort(ans.begin(), ans.end());
        int fin = INT_MAX, n = ans.size();
        for(int i=0;i<n-1;i++){
            int diff = abs(ans[i] - ans[i+1]);
            fin = min(diff, fin);
        }
        return fin;
    }
};