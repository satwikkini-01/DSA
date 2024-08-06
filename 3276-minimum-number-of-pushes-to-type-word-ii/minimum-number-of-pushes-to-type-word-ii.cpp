class Solution {
public:
    int minimumPushes(string word) {
        int f[26] = {}, ans = 0;
        for(auto it:word) f[it-'a']++;
        sort(begin(f), end(f), greater<int>());
        for (int i=0;i<26 && f[i];i++){
            ans += (f[i] * (i/8+1));
        }
        return ans;
    }
};