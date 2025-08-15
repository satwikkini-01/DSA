class Solution {
public:
    void bfs(vector<vector<int>>& isc, vector<bool>& vis, int i){
        int n = isc.size();
        queue<int>q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int j = q.front();
                q.pop();
                for(int i=0;i<n;i++){
                    if(isc[j][i] && !vis[i]){
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isc) {
        int n = isc.size(), ans = 0;
        vector<bool>vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(isc, vis, i);
                ans++;
            }
        }
        return ans;
    }
};