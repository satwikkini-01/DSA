class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        multimap<int,char>mp;
        string ans = "";
        for(auto it:s) mpp[it]++;
        for(auto it:mpp) mp.insert({it.second,it.first});
        for(auto it = mp.rbegin();it != mp.rend(); ++it) ans+=string(it->first,it->second);
        return ans;
    }
};