class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int i){
        if(vis[i]) return;
        vis[i] = true;
        for(auto it: rooms[i]){
            dfs(rooms, vis, it);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, vis, 0);
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    }
};