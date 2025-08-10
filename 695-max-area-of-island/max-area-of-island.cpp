class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int& ans){
        grid[i][j] = 0;
        ans++;
        if(i-1>=0 && grid[i-1][j] == 1) dfs(grid, i-1, j, n ,m, ans);
        if(j-1>=0 && grid[i][j-1] == 1) dfs(grid, i, j-1, n, m, ans);
        if(i+1<n && grid[i+1][j] == 1) dfs(grid, i+1, j, n, m, ans);
        if(j+1<m && grid[i][j+1] == 1) dfs(grid, i, j+1, n, m, ans);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int tmp = 0;
                    dfs(grid, i, j, n, m, tmp);
                    ans = max(tmp, ans);
                }
            }
        }
        return ans;
    }
};