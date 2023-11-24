class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size(),ans = 0,j = 0;
        for(int i=n-2;i>=0;i-=2){
            if(j>=i) break;
            ans += piles[i];
            j++;
        }
        return ans;
    }
};