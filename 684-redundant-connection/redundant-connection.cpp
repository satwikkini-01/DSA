class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    bool find(int u, int v) {
        if(findP(u) == findP(v)) return true;
        return false;
    }

    int findP(int n){
        if(parent[n] == n) return n;
        return parent[n] = findP(parent[n]);
    }

    void unionBySize(int u, int v) {
        int pu = findP(u), pv = findP(v);
        if(pu == pv) return;
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            if(ds.findP(edges[i][0]) == ds.findP(edges[i][1])) return edges[i];
            ds.unionBySize(edges[i][0], edges[i][1]);
        }
        return {};
    }
};