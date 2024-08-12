class KthLargest {
public:
    vector<int>ans;
    int k, n;
    KthLargest(int k, vector<int>& nums) {
        ans = nums;
        sort(ans.begin(), ans.end());
        this->k = k;
        n = ans.size();
    }
    
    int add(int val) {
        auto it = ans.begin();
        while(it != ans.end()){
            if(*it >= val) break;
            it++;
        }
        ans.insert(it, val);
        n++;
        return ans[n - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */