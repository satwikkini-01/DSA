class Solution {
public:
    int hammingWeight(int n) {
        int b[32];
        int i = 0, ans = 0;
        while (n > 0) {
            b[i] = n % 2;
            n = n / 2;
            i++;
        }
        for (int j=i-1;j>=0;j--) if(b[j] == 1) ans++;
        return ans;
    }
};