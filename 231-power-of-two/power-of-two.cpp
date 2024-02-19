class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        while(n>0){
            if(2%n!=0 && n%2!=0) return false;
            n/=2;
        }
        return true;
    }
};