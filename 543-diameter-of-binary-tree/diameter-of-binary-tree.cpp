class Solution {
public:
    int ans = INT_MIN;
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root -> left), height(root -> right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = height(root -> left);
        int rh = height(root -> right);
        ans = max(ans,lh+rh);
        int a = diameterOfBinaryTree(root -> left);
        int b = diameterOfBinaryTree(root -> right);
        return ans;
    }
};