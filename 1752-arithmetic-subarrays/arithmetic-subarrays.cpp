class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        int m = l.size();
        for(int i=0;i<m;i++){
            vector<int>diff;
            for(int j=l[i];j<=r[i];j++){
                diff.push_back(nums[j]);
            }
            sort(diff.begin(),diff.end());
            int flag=0;
            for(int j=0;j<diff.size()-2;j++){
                if(2*diff[j+1]!=diff[j]+diff[j+2]){
                    flag=1;
                    ans.push_back(false);
                    break;
                }
            }
            if(flag==0) ans.push_back(true);
        }
        return ans;
    }
};