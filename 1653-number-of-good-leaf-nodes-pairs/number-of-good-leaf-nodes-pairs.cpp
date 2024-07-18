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
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, vector<TreeNode*>> mpp;
        vector<TreeNode*> l;
        findLeaves(root, {}, l, mpp);
        int ans = 0, n = l.size();
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                vector<TreeNode*>& li = mpp[l[i]];
                vector<TreeNode*>& lj = mpp[l[j]];
                int n1=li.size(), n2=lj.size();
                if(n1>n2){
                    for(int k=0;k<n2;k++){
                        if(li[k]!=lj[k]){
                            if(n1+n2-2*k <= distance) ans++;
                            break;
                        }
                    }
                }
                else{
                    for(int k=0;k<n1;k++){
                        if(li[k]!=lj[k]){
                            if(n1+n2-2*k <= distance) ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }

private:
    void findLeaves(TreeNode* root, vector<TreeNode*> ans, vector<TreeNode*>& l, map<TreeNode*, vector<TreeNode*>>& mpp) {
        if (!root) return;
        vector<TreeNode*> t(ans);
        t.push_back(root);
        if (!root->left && !root->right) {
            mpp[root] = t;
            l.push_back(root);
            return;
        }
        findLeaves(root->left, t, l, mpp);
        findLeaves(root->right, t, l, mpp);
    }
};