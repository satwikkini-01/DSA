class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mpp;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                mpp[words[i][j]]++;
            }
        }
        for(auto i:mpp) if(i.second % n) return false;
        return true;
    }
};