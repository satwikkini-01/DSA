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

    int printSets() {
        set<int>s;
        for (size_t i = 0; i < parent.size(); ++i) {
            s.insert(findP(i));
        }
        return s.size();
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        int n = ac.size(), id = 0;
        map<string, int>mpp;
        map<int, string>name;
        for(int j=0;j<n;j++){
            sort(ac[j].begin()+1, ac[j].end());
            for(int i=1;i<ac[j].size();i++){
                if(!mpp.count(ac[j][i])) mpp[ac[j][i]] = id++;
                name[id-1] = ac[j][0];
            }
        }
        vector<string>toLook(id);
        for(auto it:mpp) toLook[it.second] = it.first;
        DisjointSet ds(mpp.size() - 1);
        for(int i=0;i<n;i++){
            int m = ac[i].size();
            for(int j=1;j<m;j++){
                if(j != m-1) ds.unionBySize(mpp[ac[i][j]], mpp[ac[i][j+1]]);
            }
        }
        int ts = ds.printSets();
        vector<vector<string>>ans(id);
        for(int i=0;i<id;i++){
            int pu = ds.findP(i);
            ans[pu].push_back(toLook[i]);
        }
        ans.erase(
        remove_if(ans.begin(), ans.end(),
                [](const vector<string>& tmp) { return tmp.empty(); }),
        ans.end());

        for(int i=0;i<ts;i++){
            sort(ans[i].begin(), ans[i].end());
            string nm = name[mpp[ans[i][0]]];
            ans[i].insert(ans[i].begin(), nm);
        }
        return ans;
    }
};