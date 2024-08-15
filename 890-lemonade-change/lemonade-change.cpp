class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0, t=0, n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i] == 5) f++;
            else if(bills[i] == 10){
                t++;
                if(f>0) f--;
                else return false;
            }
            else if(bills[i] == 20){
                if(t>0 && f>0){
                    t--;
                    f--;
                }
                else if(f>2){
                    f-=3;
                }
                else return false;
            }
        }
        return true;
    }
};