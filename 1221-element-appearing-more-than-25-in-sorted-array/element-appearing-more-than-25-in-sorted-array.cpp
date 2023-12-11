class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(),m=arr[0],count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==m) count++;
            else{
                m = arr[i];
                count = 1;
            }
            if(count > n/4) return arr[i];
        }
        return 1;
    }
};