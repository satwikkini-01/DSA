class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(),sum=0;
        for(auto it:nums) sum+=it;
        int l=0,r=sum;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int t = nums[i];
            r-=t;
            ans[i]=t*i-l+r-t*(n-i-1);
            l+=t;
        }
        return ans;
    }
};