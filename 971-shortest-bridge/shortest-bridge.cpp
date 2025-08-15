class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void bfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        queue<pair<int, int>>q;
        q.push({i, j});
        grid[i][j] = 2;
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(auto [di, dj] : dirs){
                int ni = a+di, nj = b+dj;
                if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj] == 1){
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), cmp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && cmp == 0){
                    bfs(grid, i, j);
                    cmp++;
                }
            }
        }
        vector<vector<int>>ans(n, vector<int>(n, -1));
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            if(grid[a][b] == 1) return ans[a][b] - 1;
            for(auto [di, dj]: dirs){
                int ni = a + di, nj = b + dj;
                if(ni>=0 && nj>=0 && ni<n && nj<n && ans[ni][nj] == -1){
                    ans[ni][nj] = ans[a][b] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return 0;
    }
};