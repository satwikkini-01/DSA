class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = -1;
        queue<pair<int, int>>q;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j] == 2) q.push({i, j});
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [a, b] = q.front();
                q.pop();
                for(auto [di, dj] : dirs){
                    int ni = a + di, nj = b + dj;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj] == 1){
                        q.push({ni, nj});
                        grid[ni][nj] = 2;
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j] == 1) return -1;
        if(ans == -1) return 0;
        return ans;
    }
};