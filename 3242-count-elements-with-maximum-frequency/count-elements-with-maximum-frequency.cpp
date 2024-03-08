class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int n = nums.size(), maxF=0, ans=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            maxF = max(maxF, freq[nums[i]]);
        }
        for(int i:freq){
            if(i == maxF) ans += i;
        }
        return ans;
    }
};