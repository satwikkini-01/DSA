class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0) return 1;
        int a=1,b=1;
        for(int i=2;i<=n;i++){
            int t=a;
            a=a+b;
            b=t;
        }
        return a;
    }
};