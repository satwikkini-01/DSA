class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<tuple<int, int, int>> mpp;
        for (int i=0;i<nums.size();i++) {
            string s = to_string(nums[i]);
            string n = "";
            for (char ch : s) n += to_string(mapping[ch - '0']);
            mpp.push_back(make_tuple(nums[i], stoi(n), i));
        }
        sort(mpp.begin(), mpp.end(), [](const auto& a, const auto& b) {
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            else return get<2>(a) < get<2>(b);
        });
        vector<int> ans(nums.size());
        for (int i=0;i<mpp.size();i++) ans[i] = get<0>(mpp[i]);
        return ans;
    }
};