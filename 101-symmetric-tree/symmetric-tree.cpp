class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp == NULL){
                    level.push_back(-101);
                    continue;
                }
                if(temp -> left != NULL) q.push(temp -> left);
                else q.push(NULL);
                if(temp -> right != NULL) q.push(temp -> right);
                else q.push(NULL);
                level.push_back(temp -> val);
            }
            int m = level.size();
            int j = m-1;
            cout<<m;
            for(int i=0;i<m/2;i++){
                if(level[i] != level[j]) return false;
                j--;
            }
        }
        return true;
    }
};