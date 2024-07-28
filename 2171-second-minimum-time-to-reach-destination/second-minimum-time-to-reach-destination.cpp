class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n];
        vector<int> dist1(n, 1e9), dist2(n, 1e9); 
        for(vector<int> &edge :edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        dist1[0] = 0;
        
        while(!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();
            if(node == n-1 && dist2[node] != 1e9) return dist2[node];

            if((currTime / change) & 1) currTime += change - (currTime % change);
            currTime += time;

            for(int &neigh :adj[node]) {
                if(dist1[neigh] == 1e9) {
                    dist1[neigh] = currTime;
                    pq.push({currTime, neigh});
                }
                else if(dist2[neigh] == 1e9 && dist1[neigh] != currTime) {
                    dist2[neigh] = currTime;
                    pq.push({currTime, neigh});
                }
            }
        }
        return -1;
    }
};