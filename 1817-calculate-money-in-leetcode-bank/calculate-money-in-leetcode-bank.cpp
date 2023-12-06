class Solution {
public:
    int totalMoney(int n) {
        int d = n/7, r = n%7;
        int tmp = d*28;
        for(int i=1;i<d;i++) tmp+=(7*i);
        for(int i=0;i<r;i++){
            tmp+=(d+1);
            d++;
        }
        return tmp;
    }
};