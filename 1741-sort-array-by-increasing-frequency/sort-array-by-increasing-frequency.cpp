class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (mpp[n1] != mpp[n2]) return mpp[n1] < mpp[n2];
            else return n2 < n1;
        });
        return nums;
    }
};