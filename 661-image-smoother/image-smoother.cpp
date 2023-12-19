class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int total_sum=0,count=0;
                for (int l=max(0,i-1);l<min(n,i+2);l++){
                    for (int k=max(0,j-1);k<min(m,j+2);k++){
                        total_sum += img[l][k];
                        count += 1;
                    }
                }
                ans[i][j] = total_sum / count;
            }
        }
        return ans;
    }
};