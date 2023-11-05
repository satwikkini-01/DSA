class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k==1) return max(arr[0],arr[1]);
        if(k>=n) return *max_element(arr.begin(),arr.end());
        int tmp=arr[0],ans=0;
        for(int i=1;i<n;i++){
            if(tmp>arr[i]) ans++;
            else{
                tmp=arr[i];
                ans=1;
            }
            if(ans==k) return tmp;
        }
        return tmp;
    }
};