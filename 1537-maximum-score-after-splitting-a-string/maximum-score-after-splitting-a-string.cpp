class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ans = 0;
        for(int i=0;i<n-1;i++){
            int tmp = 0;
            for(int j=0;j<=i;j++) if(s[j] == '0') tmp++;
            for(int j=i+1;j<n;j++) if(s[j] == '1') tmp++;
            ans = max(ans, tmp);
        }
        return ans;
    }
};