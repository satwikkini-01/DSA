class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0) return false;
        int chk = x;
        long long rev = x % 10;
        x /= 10;
        while(x > 0){
            int r = x % 10;
            x /= 10;
            rev *= 10;
            rev += r;
        }
        if(rev == chk) return true;
        return false;
    }
};