class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sub;
        for(int i=0;i<n;i++){
            int t = 0;
            for(int j=i;j<n;j++){
                t += nums[j];
                sub.push_back(t);
            }
        }
        sort(sub.begin(), sub.end());
        int ans = 0;
        for(int i=left-1;i<right;i++) ans = (sub[i] + ans) % mod;
        return ans;
    }
};