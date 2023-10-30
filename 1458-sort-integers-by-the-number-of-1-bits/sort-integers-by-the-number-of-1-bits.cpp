#define btcnt __builtin_popcount 
class Solution {
public:
    static bool compare(int& a,int& b){
        int x=btcnt(a);
        int y=btcnt(b);
        if(x==y) return a<b;
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), compare);
        return arr;
    }
};