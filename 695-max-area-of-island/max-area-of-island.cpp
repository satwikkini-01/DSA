class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int& cnt){
        vis[i][j] = true;
        cnt++;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(auto [di, dj]: dirs){
            int ni = i+di, nj = j+dj;
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && !vis[ni][nj] && grid[ni][nj]){
                dfs(grid, vis, ni, nj, cnt);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    int tmp = 0;
                    dfs(grid, vis, i, j, tmp);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};