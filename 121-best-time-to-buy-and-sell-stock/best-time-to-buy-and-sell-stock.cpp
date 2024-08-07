class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0, m = prices[0];
        for(int i=1;i<n;i++){
            int t = prices[i] - m;
            ans = max(ans, t);
            m = min(m, prices[i]);
        }
        return ans;
    }
};