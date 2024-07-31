class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n = books.size();
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int w=0, h=0, k=1;
            while(k <= i){
                h = max(h, books[i-k][1]);
                w += books[i-k][0];
                if(w > sw) break;
                dp[i] = min(dp[i], dp[i-k]+h);
                k++;
            }
        }
        return dp[n];
    }
};