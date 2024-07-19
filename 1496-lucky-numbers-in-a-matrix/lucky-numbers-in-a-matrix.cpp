class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>m1, m2,ans;
        for(int i=0;i<n;i++){
            int mi = INT_MAX;
            for(int j=0;j<m;j++){
                if(matrix[i][j] < mi) mi = matrix[i][j];
            }
            m1.push_back(mi);
        }
        for(int i=0;i<m;i++){
            int mi = INT_MIN;
            for(int j=0;j<n;j++){
                if(matrix[j][i] > mi) mi = matrix[j][i];
            }
            m2.push_back(mi);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(m1[i] == m2[j]) ans.push_back(m1[i]);
            }
        }
        return ans;
    }
};