class Solution {
public:
    bool canConstruct(string r, string m) {
        map<int, int> m1, m2;
        for(auto it:r) m1[it]++;
        for(auto it:m) m2[it]++;
        for(auto [a,b]: m1){
            if(m2[a] < b) return false;
        }
        return true;
    }
};