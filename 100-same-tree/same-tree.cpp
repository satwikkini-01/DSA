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
    void preOrder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root -> val);
        preOrder(root -> left,ans);
        preOrder(root -> right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root, ans);
        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a = preorderTraversal(p);
        vector<int> b = preorderTraversal(q);
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};