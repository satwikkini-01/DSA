class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        queue<pair<int, int>>q;
        q.push({i, j});
        grid[i][j] = 0;
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            if(b+1<m && grid[a][b+1] == '1'){
                grid[a][b+1] = 0;
                q.push({a, b+1});
            }
            if(a+1<n && grid[a+1][b] == '1'){
                grid[a+1][b] = 0;
                q.push({a+1, b});
            }
            if(b-1>=0 && grid[a][b-1] == '1'){
                grid[a][b-1] = 0;
                q.push({a, b-1});
            }
            if(a-1>=0 && grid[a-1][b] == '1'){
                grid[a-1][b] = 0;
                q.push({a-1, b});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    bfs(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};