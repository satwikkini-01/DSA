class Solution {
public:
        void combination2Correct(vector<int>& nums, int target, vector<vector<int> >& ans, vector<int>& store, int i){
        if(target == 0){
            ans.push_back(store);
            return;
        }
        for(int j = i;j<nums.size();j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            if(nums[j] > target) break;
            store.push_back(nums[j]);
            combination2Correct(nums, target - nums[j], ans, store, j+1);
            store.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> >ans;
        sort(candidates.begin(), candidates.end());
        vector<int>store;
        combination2Correct(candidates, target, ans, store, 0);
        return ans;
    }
};