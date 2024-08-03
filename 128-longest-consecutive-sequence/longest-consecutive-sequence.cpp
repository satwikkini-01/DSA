class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        int ans = 0, m = mpp.size(), count = 1;
        for (auto it=mpp.begin();it!=prev(mpp.end());it++){
            cout<<it->first<<" ";
            auto next_it = next(it);
            if (it->first + 1 == next_it->first) count++;
            else{
                ans = max(ans, count);
                count = 1;
            }
        }
        return max(ans, count);
    }   
};