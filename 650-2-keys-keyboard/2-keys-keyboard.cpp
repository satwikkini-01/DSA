class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i < n/2; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        if(isPrime(n)) return n;
        vector<int>dp;
        int fact = 2, ans = 0;
        while(n > 1){
            if(n % fact == 0){
                dp.push_back(fact);
                n /= fact;
            }
            else fact++;
        }
        for(int i=0;i<dp.size();i++){
            if(isPrime(dp[i])) ans += dp[i];
        }
        return ans;
    }
};