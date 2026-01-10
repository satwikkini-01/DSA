class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while(i < (nums.size() - 1)){
            if(nums[i] != nums[i+1]) i++;
            else{
                if(i+2 < nums.size() && nums[i] == nums[i+2]) nums.erase(nums.begin() + i + 2);
                else i += 2;
            }
        }
        return nums.size();
    }
};