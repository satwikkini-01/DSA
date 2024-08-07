class Solution {
public:
    string one[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string two[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string more[5] = {"", " Thousand", " Million", " Billion"};

    string rec(int n){
        if(n < 20) return one[n];
        if(n < 100) return two[n/10] + rec(n%10);
        if(n < 1000) return rec(n/100) + " Hundred" + rec(n%100);
        else{
            for(int i=5;i>=0;i--){
                if(n >= pow(1000, i)){
                    return rec(n/pow(1000,i)) + more[i] + rec(n%(int)pow(1000,i));
                }
            }
        }
        return "";
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return rec(num).substr(1);
    }
};