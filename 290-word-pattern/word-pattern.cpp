class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char, string>mpp1;
        map<string, char>mpp2;
        int n = p.size();
        vector<string>ss;
        string s1 = "";
        for(auto it:s){
            if(it != ' ') s1.push_back(it);
            else{
                ss.push_back(s1);
                s1 = "";
            }
        }
        ss.push_back(s1);
        int m = ss.size();
        if(n != m) return false;
        for(int i=0;i<n;i++){
            if(!mpp1.count(p[i]) && !mpp2.count(ss[i])){
                mpp1[p[i]] = ss[i];
                mpp2[ss[i]] = p[i];
            }
            if(mpp1[p[i]] != ss[i] || mpp2[ss[i]] != p[i]) return false;
        }
        return true;
    }
};