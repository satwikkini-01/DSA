class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0], ans = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i] < m) m = prices[i];
            else{
                int d = prices[i] - m;
                ans = max(d, ans);
            }
        }
        return ans;
    }
};