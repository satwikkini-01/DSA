class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(k>j){
                sum=nums[i]+nums[j]+nums[k];
                if(abs(sum - target) < abs(ans - target)) ans = sum;
                if(sum==target){
                    return target;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};