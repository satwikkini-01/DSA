class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long int>pre;
        sort(nums.begin(),nums.end());
        long long n = nums.size(), temp=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];
            pre.push_back(temp);
        }
        for(int i=n-2;i>=1;i--){
            if(pre[i]>nums[i+1]) return pre[i+1];
        }
        return -1;
    }
};
// 1 1 2 3 5 12 50
// 1 2 4 7 12 24 74
// 5 5 5
// 5 10 15