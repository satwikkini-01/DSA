class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis){
        vis[i][j] = true;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(auto [di, dj]: dirs){
            int ni = i+di, nj = j+dj;
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && !vis[ni][nj] && grid[ni][nj] == '1')
            dfs(grid, ni, nj, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, i, j, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};