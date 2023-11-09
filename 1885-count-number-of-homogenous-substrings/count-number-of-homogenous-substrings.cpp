class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(),ans=1,curr=1;
        int mod = 1000000007;
        for(int i=1;i<n;i++){
            int count = 1;
            if(s[i]==s[i-1]) count=(count+curr)%mod;
            ans=(ans+count)%mod;
            curr=count;
        }
        return ans;
    }
};