class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>mpp, mpp1;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!mpp.count(s[i]) && !mpp1.count(t[i])){
                mpp[s[i]] = t[i];
                mpp1[t[i]] = s[i];
            }
            if(mpp[s[i]] != t[i] || mpp1[t[i]] != s[i]) return false;
        }
        return true;
    }
};