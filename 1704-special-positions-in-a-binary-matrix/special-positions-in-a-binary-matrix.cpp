class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0, n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) continue;
                int cnt = 0;
                for(int x=0;x<m;x++){
                    if(mat[i][x] == 1) cnt++;
                }
                for(int x=0;x<n;x++){
                    if(mat[x][j] == 1) cnt++;
                }
                if(cnt == 2) count++;
            }
        }
        return count;
    }
};