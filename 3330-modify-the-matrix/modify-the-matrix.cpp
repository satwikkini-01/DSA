class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> >answer(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    int z = INT_MIN;
                    for(int k=0;k<m;k++){
                        z = max(z,matrix[k][j]);
                    }
                    answer[i][j] = z;
                }
                else{
                    answer[i][j] = matrix[i][j];
                }
            }
        }
        return answer;
    }
};