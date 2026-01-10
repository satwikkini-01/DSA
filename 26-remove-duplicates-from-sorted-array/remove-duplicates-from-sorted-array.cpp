class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while(i < (nums.size() - 1)){
            if(nums[i] != nums[i+1]) i++;
            else{
                nums.erase(nums.begin() + i + 1);
            }
        }
        return nums.size();
    }
};