class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'Y';
                q.push({i, 0});
            }
            if(board[i][m-1] == 'O'){
                board[i][m-1] = 'Y';
                q.push({i, m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'Y';
                q.push({0, i});
            }
            if(board[n-1][i] == 'O'){
                board[n-1][i] = 'Y';
                q.push({n-1, i});
            }
        }
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(auto [di, dj]: dirs){
                int ni = a+di, nj = b+dj;
                if(ni>=0 && nj>=0 && ni<n && nj<m && board[ni][nj] == 'O'){
                    q.push({ni, nj});
                    board[ni][nj] = 'Y';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};