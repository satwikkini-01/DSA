class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int sum = 0;
        for(auto it:nums) if(it >= 0) st.insert(it);
        for(auto it:st) sum += it;
        sort(nums.begin(), nums.end());
        if(nums[nums.size() - 1] < 0) return nums[nums.size() - 1];
        return sum;
    }
};