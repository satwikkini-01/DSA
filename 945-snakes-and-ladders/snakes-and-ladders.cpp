class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int>snl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int z = n - 1 - i, y = j;
                if(z % 2 == 1) y = n - 1 - j;
                int num = (z * n) + y + 1;
                if(board[i][j] != -1) snl[num] = board[i][j];
                board[i][j] = num;
            }
        }
        queue<int>q;
        unordered_set<int>vis;
        int ans = 0;
        q.push(1);
        vis.insert(1);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int tmp = q.front();
                q.pop();
                if(tmp == n*n) return ans;
                for(int i=1;i<=6;i++){
                    int nxt = tmp + i;
                    if (nxt > n * n) continue;
                    if (snl.count(nxt)) nxt = snl[nxt];
                    if (!vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};