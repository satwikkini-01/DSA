class Solution {
public:
    int ans = INT_MIN;
    int diameterOfBinaryTreeRec(TreeNode* root){
        if(root == NULL) return 0;
        int lh = diameterOfBinaryTreeRec(root -> left);
        int rh = diameterOfBinaryTreeRec(root -> right);
        ans = max(ans,lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a = diameterOfBinaryTreeRec(root);
        return ans;
    }
};