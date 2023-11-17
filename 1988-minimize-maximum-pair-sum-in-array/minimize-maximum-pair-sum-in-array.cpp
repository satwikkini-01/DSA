class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(),ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            int t = nums[i]+nums[n-i-1];
            ans=max(ans,t);
        }
        return ans;
    }
};