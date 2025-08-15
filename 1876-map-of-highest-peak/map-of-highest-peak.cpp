class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isw) {
        int n = isw.size(), m = isw[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isw[i][j]){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(auto [i, j] : dirs){
                int ni = a + i, nj = b + j;
                if(ni>=0 && nj>=0 && ni<n && nj<m && ans[ni][nj] == -1){
                    ans[ni][nj] = ans[a][b] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return ans;
    }
};