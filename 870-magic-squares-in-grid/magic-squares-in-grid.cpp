class Solution {
public:
    bool grd(int x, int y, vector<vector<int>>& grid) {
        vector<int> count(10, 0);
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                int num = grid[i+x][j+y];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }
        int sum = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        for(int i=0;i<3;i++) if(sum != (grid[i+x][y] + grid[i+x][y+1] + grid[i+x][y+2])) return false;
        for(int j=0;j<3;j++) if(sum != (grid[x][j+y] + grid[x+1][j+y] + grid[x+2][j+y])) return false;
        if(sum != (grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2]) || (sum != (grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2]))) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0;i<n-2;i++) for(int j=0;j<m-2;j++) if(grd(i, j, grid)) ans++;
        return ans;
    }
};