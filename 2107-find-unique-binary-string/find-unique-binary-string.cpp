class Solution {
public:
    string decToBinary(int n,int a) { 
        string ans = ""; 
        for (int i = a; i >= 0; i--) { 
            int k = n >> i; 
            if (k & 1) 
                ans+='1';
            else
                ans+='0';
        } 
        return ans;
    } 

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int a = nums[0].size();
        vector<int>ans;
        for(auto it:nums){
            int num = stoi(it, 0, 2);
            ans.push_back(num);
        }
        int i=0;
        string fin = decToBinary(ans[ans.size()-1]+1,a-1);
        sort(ans.begin(),ans.end());
        while(true && i<n){
            if(ans[i] != i){
                fin = decToBinary(i,a-1);
                break;
            }
            i++;
        }
        return fin;
    }
};