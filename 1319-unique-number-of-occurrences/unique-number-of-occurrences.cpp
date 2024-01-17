class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mpp;
        for(auto it:arr) mpp[it]++;
        set<int>s;
        for(auto it:mpp) s.insert(it.second);
        if(mpp.size() == s.size()) return true;
        return false;
    }
};