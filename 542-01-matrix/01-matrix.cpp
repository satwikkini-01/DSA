class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [a, b] = q.front();
                q.pop();
                for(auto [di, dj] : dirs){
                    int ni = a + di, nj = b + dj;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && ans[ni][nj] == -1){
                        ans[ni][nj] = ans[a][b] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
        return ans;
    }
};