class DisjointSet {
public:
    vector<int>parent, size;
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
    bool equationsPossible(vector<string>& eq) {
        int n = eq.size();
        vector<string> ee, ne;
        for(int i=0;i<n;i++){
            if(eq[i][1] == '=') ee.push_back(eq[i]);
            else ne.push_back(eq[i]);
        }
        DisjointSet ds(26);
        for(int i=0;i<ee.size();i++){
            ds.unionBySize(((int)ee[i][0] - 97), ((int)ee[i][3] - 97));
        }
        for(int i=0;i<ne.size();i++){
            int pu = ds.findP((int)ne[i][0] - 97);
            int pv = ds.findP((int)ne[i][3] - 97);
            if(pu == pv) return false;
        }
        return true;
    }
};