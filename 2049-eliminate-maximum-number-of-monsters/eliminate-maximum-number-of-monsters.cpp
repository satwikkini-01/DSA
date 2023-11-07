class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>mons;
        for(int i=0;i<n;i++){
            int t = ceil(dist[i]/(double)speed[i]);
            mons.push_back(t);
        }
        sort(mons.begin(),mons.end());
        for(int i=0;i<n;i++){
            if(mons[i]<=i) return i;
        }
        return n;
    }
};