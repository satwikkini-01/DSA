class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, count = 1;
        vector<int>freq(256, 0);
        int l=0, r=0;
        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            r++;
            ans = max(ans, (r-l));
        }
        return ans;
    }
};