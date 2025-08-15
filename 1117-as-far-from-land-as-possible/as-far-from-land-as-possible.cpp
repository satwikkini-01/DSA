class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, -1));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(auto [i, j]: dirs){
                int ni = a+i, nj = b+j;
                if(ni>=0 && nj>=0 && ni<n && nj<n && ans[ni][nj] == -1){
                    ans[ni][nj] = ans[a][b] + 1;
                    q.push({ni, nj});
                }
            }
        }
        int ans1 = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j] > ans1) ans1 = ans[i][j];
            }
        }
        if(ans1 == 0) return -1;
        return ans1;
    }
};