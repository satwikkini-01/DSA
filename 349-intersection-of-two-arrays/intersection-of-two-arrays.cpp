class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mpp(nums1.begin(), nums1.end());
        vector<int>ans;
        for(auto it: nums2){
            if(mpp.count(it)){
                ans.push_back(it);
                mpp.erase(it);
            }
        }
        return ans;
    }
};