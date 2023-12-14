class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>onesRow(m,0);
        vector<int>zerosRow(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                onesRow[i] += grid[i][j];
                zerosRow[j] += grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = 2 * (onesRow[i]+zerosRow[j]) -m -n;
            }
        }
        return grid;
    }
};