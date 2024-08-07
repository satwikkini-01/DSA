class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n-1, ans = 0;
        while(l < r){
            int mi = min(h[l],h[r]);
            int t = mi * (r-l);
            cout<<t<<" ";
            ans = max(ans, t);
            if(h[l] == h[r]){
                if((l+1)<r && h[l+1] > h[r-1]) l++;
                else r--;
            }
            else if(mi == h[l]) l++;
            else r--;
        }
        return ans;
    }
};