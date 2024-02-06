class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mpp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string a = strs[i];
            sort(a.begin(),a.end());
            mpp[a].push_back(strs[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};