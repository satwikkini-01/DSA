class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int count = 1, d = 0;
        while(ans.size() < (rows * cols)){
            for(int i=0;i<2;i++){
                for(int j=0;j<count;j++){
                    if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols) ans.push_back({rStart, cStart});
                    rStart += dir[d][0];
                    cStart += dir[d][1];
                }
                d = (d + 1) % 4;
            }
            count++;
        }
        return ans;
    }
};