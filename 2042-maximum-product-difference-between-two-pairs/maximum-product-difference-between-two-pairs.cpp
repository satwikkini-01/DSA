class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[n-1] * nums[n-2];
        int b = nums[0] * nums[1];
        return (a - b);
    }
};