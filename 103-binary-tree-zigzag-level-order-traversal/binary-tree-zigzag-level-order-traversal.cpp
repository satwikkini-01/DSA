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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int c=0;
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp -> right != NULL) q.push(temp -> right);
                if(temp -> left != NULL) q.push(temp -> left);
                level.push_back(temp -> val);
            }
            if(c%2==0){
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            else{
                ans.push_back(level);
            }
            c++;
        }
        return ans;
    }
};