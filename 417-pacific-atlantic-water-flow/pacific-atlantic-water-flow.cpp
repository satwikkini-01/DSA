class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size(), ans = 0;
        vector<vector<bool>> pac(n, vector<bool>(m, false)), atl(n, vector<bool>(m, false));
        queue<pair<int, int>>q1, q2;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0;i<n;i++){
            pac[i][0] = true;
            atl[i][m-1] = true;
            q1.push({i, 0});
            q2.push({i, m-1});
        }
        for(int i=0;i<m;i++){
            pac[0][i] = true;
            atl[n-1][i] = true;
            q1.push({0, i});
            q2.push({n-1, i});
        }
        while(!q1.empty()){
            auto [a, b] = q1.front();
            q1.pop();
            for(auto [di, dj]: dirs){
                int ni = a + di, nj = b + dj;
                if(ni>=0 && nj>=0 && ni<n && nj<m && heights[ni][nj] >= heights[a][b] && !pac[ni][nj]){
                    q1.push({ni, nj});
                    pac[ni][nj] = true;
                }
            }
        }
        while(!q2.empty()){
            auto [a, b] = q2.front();
            q2.pop();
            for(auto [di, dj]: dirs){
                int ni = a + di, nj = b + dj;
                if(ni>=0 && nj>=0 && ni<n && nj<m && heights[ni][nj] >= heights[a][b] && !atl[ni][nj]){
                    q2.push({ni, nj});
                    atl[ni][nj] = true;
                }
            }
        }
        vector<vector<int>>ans1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]) ans1.push_back({i, j});
            }
        }
        return ans1;
    }
};