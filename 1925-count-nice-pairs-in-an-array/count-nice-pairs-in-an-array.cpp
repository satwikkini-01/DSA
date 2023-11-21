class Solution {
public:
    int rev(int t){
        int ans = 0;
        while(t>0){
            int r = t%10;
            ans = ans * 10 + r;
            t/=10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size(),mod=1000000007;
        for(int i=0;i<n;i++) nums[i] = nums[i]-rev(nums[i]);
        sort(nums.begin(),nums.end());
        long ans=0;
        for (int i = 0; i < n - 1; i++) {
            long count = 1;
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                count++;
                i++;
            }
            ans = (ans % mod + (count * (count - 1)) / 2) % mod;
        }
        return ans;
    }
};