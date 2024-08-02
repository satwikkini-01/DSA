class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i=0;i<n;i++) if (nums[i] == 1) cnt++;
        if (cnt == 0) return 0;
        int count = 0, m = 0;
        for (int i=0;i<cnt;i++) if (nums[i] == 1) count++;
        m = count;
        for (int i=cnt;i<n+cnt;i++) {
            if (nums[i % n] == 1) count++;
            if (nums[(i - cnt) % n] == 1) count--;
            m = max(m, count);
        }
        return cnt - m;
    }
};
