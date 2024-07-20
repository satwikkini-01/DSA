class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size(), i = 0, j = 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));

        while (i<n || j<m) {
            if (i >= n) {
                ans[n-1][j] = colSum[j];
                j++;
            } 
            else if (j >= m) {
                ans[i][m-1] = rowSum[i];
                i++;
            }
            else{
                int r = min(rowSum[i], colSum[j]);
                rowSum[i] -= r;
                colSum[j] -= r;
                ans[i][j] = r;
                if(rowSum[i] == 0) i++;
                if(colSum[j] == 0) j++;
            }
        }
        return ans;
    }
};